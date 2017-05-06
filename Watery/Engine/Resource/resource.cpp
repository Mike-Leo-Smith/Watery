//
// Created by Mike Smith on 2017/4/17.
//

#include <AL/alut.h>
#include <string>
#include <fstream>
#include <sstream>
#include "resource.h"
#include "../../Framework/Image/lodepng.h"

namespace watery
{
	Resource *Resource::_instance = new Resource;
	
	const GLTexture *Resource::create_texture(const std::string &texture_name, const std::string &file_name)
	{
		GLTexture *texture;
		
		if (_textures.count(texture_name))
		{
			texture = _textures.at(file_name);
		}
		else
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
	
	const GLShader *Resource::create_shader(const std::string &shader_name, const std::string &vertex_shader_file_name, const std::string &fragment_shader_file_name)
	{
		GLShader *shader;
		
		if (_shaders.count(shader_name))
		{
			shader = _shaders.at(shader_name);
		}
		else
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
				
				std::string vertex_shader_code;
				std::string fragment_shader_code;
				
				vertex_shader_code = vertex_shader_code_stream.str();
				fragment_shader_code = fragment_shader_code_stream.str();
				
				shader = new GLShader(vertex_shader_code.c_str(), fragment_shader_code.c_str());
				_shaders.emplace(shader_name, shader);
			}
			else
			{
				shader = nullptr;
			}
		}
		
		return shader;
		
	}
	
	const ALAudio *Resource::create_audio(const std::string &audio_name, const std::string &file_name)
	{
		ALAudio *audio;
		
		if (_audios.count(audio_name))
		{
			audio = _audios.at(file_name);
		}
		else
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
	
	const GLShader *Resource::get_shader(const std::string &shader_name) const
	{
		GLShader *shader = nullptr;
		
		if (_textures.count(shader_name))
		{
			shader = _shaders.at(shader_name);
		}
		
		return shader;
	}
	
	const GLTexture *Resource::get_texture(const std::string &texture_name) const
	{
		GLTexture *texture = nullptr;
		
		if (_textures.count(texture_name))
		{
			texture = _textures.at(texture_name);
		}
		
		return texture;
	}
	
	const ALAudio *Resource::get_audio(const std::string &audio_name) const
	{
		ALAudio *audio = nullptr;
		
		if (_audios.count(audio_name))
		{
			audio = _audios.at(audio_name);
		}
		
		return audio;
	}
	
	void Resource::destroy_shader(const std::string &shader_name)
	{
		if (_shaders.count(shader_name))
		{
			delete _shaders.at(shader_name);
			_textures.erase(shader_name);
		}
	}
	
	void Resource::destroy_texture(const std::string &texture_name)
	{
		if (_textures.count(texture_name))
		{
			delete _textures.at(texture_name);
			_textures.erase(texture_name);
		}
	}
	
	void Resource::destroy_audio(const std::string &audio_name)
	{
		if (_audios.count(audio_name))
		{
			delete _audios.at(audio_name);
			_audios.erase(audio_name);
		}
	}
	
	Resource::~Resource(void)
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
	}
}