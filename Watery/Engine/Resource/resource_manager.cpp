//
// Created by Mike Smith on 2017/4/17.
//

#include <gl/glew.h>
#include <AL/alut.h>
#include <string>
#include <fstream>
#include <sstream>
#include "resource_manager.h"
#include "../../Framework/ThirdParty/lodepng.h"

namespace watery
{
	GLTexture *ResourceManager::get_texture(const std::string &texture_name, const std::string &file_name)
	{
		GLTexture *texture = nullptr;
		
		if (_textures.count(texture_name))
		{
			texture = _textures.at(texture_name);
		}
		else if (file_name != "")
		{
			constexpr int depth = 4;
			unsigned int width, height;
			std::vector<unsigned char> pixels;
			
			lodepng::decode(pixels, width, height, file_name);
			texture = new GLTexture(pixels.data(), width, height, depth);
			
			_textures.emplace(texture_name, texture);
		}
		
		return texture;
	}
	
	GLShader *ResourceManager::get_shader(const std::string &shader_name, const std::string &file_name)
	{
		GLShader *shader = nullptr;
		size_t colon_pos = file_name.find(':');
		
		std::string vertex_shader_file_name = file_name.substr(0, colon_pos);
		std::string fragment_shader_file_name = file_name.substr(colon_pos + 1);
		
		if (_shaders.count(shader_name))
		{
			shader = _shaders.at(shader_name);
		}
		else if (vertex_shader_file_name != "" && fragment_shader_file_name != "")
		{
			std::ifstream vertex_shader_file;
			std::ifstream fragment_shader_file;
			
			vertex_shader_file.open(vertex_shader_file_name);
			fragment_shader_file.open(fragment_shader_file_name);
			
			if (vertex_shader_file.is_open() && fragment_shader_file.is_open())
			{
				std::stringstream vertex_shader_code_stream;
				std::stringstream fragment_shader_code_stream;
				
				vertex_shader_code_stream << vertex_shader_file.rdbuf();
				fragment_shader_code_stream << fragment_shader_file.rdbuf();
				
				std::string vertex_shader_code;
				std::string fragment_shader_code;
				
				vertex_shader_code = vertex_shader_code_stream.str();
				fragment_shader_code = fragment_shader_code_stream.str();
				
				shader = new GLShader(vertex_shader_code.c_str(), fragment_shader_code.c_str());
				_shaders.emplace(shader_name, shader);
			}
		}
		
		return shader;
	}
	
	ALAudio *ResourceManager::get_audio(const std::string &audio_name, const std::string &file_name)
	{
		ALAudio *audio = nullptr;
		
		if (_audios.count(audio_name))
		{
			audio = _audios.at(audio_name);
		}
		else if (file_name != "")
		{
			ALenum format;
			ALsizei size;
			ALsizei freq;
			ALvoid *data;
			
			// Function alutCreateBufferFromFile() dose not work properly here, do we have to use the deprecated methods.
			alutLoadWAVFile((ALbyte *)file_name.c_str(), &format, &data, &size, &freq);
			audio = new ALAudio(data, format, size, freq);
			alutUnloadWAV(format, data, size, freq);
			
			_audios.emplace(audio_name, audio);
		}
		
		return audio;
	}
	
	void ResourceManager::destroy_shader(const std::string &shader_name)
	{
		if (_shaders.count(shader_name))
		{
			delete _shaders.at(shader_name);
			_textures.erase(shader_name);
		}
	}
	
	void ResourceManager::destroy_texture(const std::string &texture_name)
	{
		if (_textures.count(texture_name))
		{
			delete _textures.at(texture_name);
			_textures.erase(texture_name);
		}
	}
	
	void ResourceManager::destroy_audio(const std::string &audio_name)
	{
		if (_audios.count(audio_name))
		{
			delete _audios.at(audio_name);
			_audios.erase(audio_name);
		}
	}
	
	void ResourceManager::destroy_vertex_array(const std::string &vertex_array_name)
	{
		if (_vertex_arrays.count(vertex_array_name))
		{
			delete _vertex_arrays.at(vertex_array_name);
			_vertex_arrays.erase(vertex_array_name);
		}
	}
	
	ResourceManager::~ResourceManager(void)
	{
		destroy_all();
	}
	
	GLVertexArray *ResourceManager::get_vertex_array(const std::string &vertex_array_name, const std::string &file_name)
	{
		GLVertexArray *vertex_array = nullptr;
		
		if (_vertex_arrays.count(vertex_array_name))
		{
			vertex_array = _vertex_arrays.at(vertex_array_name);
		}
		else if (file_name != "")
		{
			std::ifstream file(file_name);
			
			if (file.is_open())
			{
				vertex_array = new GLVertexArray;
				_vertex_arrays.emplace(vertex_array_name, vertex_array);
				
				std::string s;
				
				while (!file.eof())
				{
					file >> s;
					
					if (s == "#")
					{
						break;
					}
					
					if (s == ">")
					{
						GLuint index;
						GLuint size;
						GLuint stride;
						GLuint offset;
						
						// Read pointer attributes.
						file >> index >> size >> stride >> offset;
						vertex_array->set_pointers(index, size, stride, offset);
					}
					else if (s == "{")
					{
						GLsizei count = 0;
						std::vector<float> vertices;
						
						file >> s;
						while (s != "}")
						{
							if (s == ".")
							{
								file >> count;
							}
							else
							{
								vertices.push_back((float)atof(s.c_str()));
							}
							file >> s;
						}
						vertex_array->load(vertices.data(), (GLsizei)vertices.size());
						vertex_array->set_count(count);
					}
				}
			}
		}
		
		return vertex_array;
	}
	
	void ResourceManager::destroy_all(void)
	{
		for (auto &texture : _textures)
		{
			delete texture.second;
		}
		
		for (auto &audio : _audios)
		{
			delete audio.second;
		}
		
		for (auto &shader : _shaders)
		{
			delete shader.second;
		}
		
		for (auto &vertex_array : _vertex_arrays)
		{
			delete vertex_array.second;
		}
		
		_textures.clear();
		_audios.clear();
		_shaders.clear();
		_vertex_arrays.clear();
	}
	
	ResourceManager &ResourceManager::instance(void)
	{
		static ResourceManager manager;
		return manager;
	}
}