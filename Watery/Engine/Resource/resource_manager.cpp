//
// Created by Mike Smith on 2017/4/17.
//

#include <gl/glew.h>
#include <AL/alut.h>
#include <string>
#include <fstream>
#include <sstream>
#include "resource_manager.h"
#include "../../Framework/3rdParty/lodepng.h"

namespace watery
{
	ResourceManager *ResourceManager::_instance = new ResourceManager;
	
	GLTexture *ResourceManager::get_texture(const std::string &texture_name, const std::string &file_name)
	{
		GLTexture *texture = nullptr;
		
		if (_textures.count(texture_name))
		{
			texture = _textures.at(file_name);
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
	
	GLShader *ResourceManager::get_shader(const std::string &shader_name, const std::string &vertex_shader_file_name, const std::string &fragment_shader_file_name)
	{
		GLShader *shader = nullptr;
		
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
			audio = _audios.at(file_name);
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
	
	ResourceManager::~ResourceManager(void)
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
	}
	
	GLVertexArray *ResourceManager::get_vertex_array(const std::string &vertex_array_name, const std::string &vertex_array_file)
	{
		GLVertexArray *vertex_array = nullptr;
		
		if (_vertex_arrays.count(vertex_array_name))
		{
			vertex_array = _vertex_arrays.at(vertex_array_name);
		}
		else if (vertex_array_file != "")
		{
			std::ifstream file(vertex_array_file);
			
			if (file.is_open())
			{
				vertex_array = new GLVertexArray;
				_vertex_arrays.emplace(vertex_array_name, vertex_array);
				
				std::string s;
				
				file >> s;
				while (s != "#")
				{
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
						GLsizei elements = 0;
						std::vector<float> vertices;
						
						file >> s;
						while (s != "}")
						{
							if (s == ".")
							{
								file >> elements;
							}
							else
							{
								vertices.push_back((float)atof(s.c_str()));
							}
							file >> s;
						}
						vertex_array->load(vertices.data(), (GLsizei)vertices.size(), elements);
					}
					file >> s;
				}
			}
		}
		
		return vertex_array;
	}
}