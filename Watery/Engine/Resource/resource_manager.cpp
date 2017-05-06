//
// Created by Mike Smith on 2017/5/7.
//

#include "resource_manager.h"

namespace watery
{
	const GLShader *ResourceManager::create_shader(const std::string &shader_name, const std::string &vertex_shader_file_name, const std::string &fragment_shader_file_name)
	{
		return _resource.create_shader(shader_name, vertex_shader_file_name, fragment_shader_file_name);
	}
	
	const GLTexture *ResourceManager::create_texture(const std::string &texture_name, const std::string &file_name)
	{
		return _resource.create_texture(texture_name, file_name);
	}
	
	const ALAudio *ResourceManager::create_audio(const std::string &audio_name, const std::string &file_name)
	{
		return _resource.create_audio(audio_name, file_name);
	}
	
	const GLShader *ResourceManager::get_shader(const std::string &shader_name) const
	{
		return _resource.get_shader(shader_name);
	}
	
	const GLTexture *ResourceManager::get_texture(const std::string &texture_name) const
	{
		return _resource.get_texture(texture_name);
	}
	
	const ALAudio *ResourceManager::get_audio(const std::string &audio_name) const
	{
		return _resource.get_audio(audio_name);
	}
	
	void ResourceManager::destroy_texture(const std::string &texture_name)
	{
		_resource.destroy_texture(texture_name);
	}
	
	void ResourceManager::destroy_audio(const std::string &audio_name)
	{
		_resource.destroy_audio(audio_name);
	}
	
	void ResourceManager::destroy_shader(const std::string &shader_name)
	{
		_resource.destroy_shader(shader_name);
	}
}