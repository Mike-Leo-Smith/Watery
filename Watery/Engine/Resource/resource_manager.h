//
// Created by Mike Smith on 2017/5/7.
//

#ifndef WATERY_RESOURCE_MANAGER_H
#define WATERY_RESOURCE_MANAGER_H

#include "resource.h"

namespace watery
{
	class ResourceManager
	{
	private:
		Resource &_resource;
	
	public:
		ResourceManager(void) : _resource(Resource::instance()) {}
		virtual const GLShader *create_shader(const std::string &shader_name, const std::string &vertex_shader_file_name, const std::string &fragment_shader_file_name);
		virtual const GLTexture *create_texture(const std::string &texture_name, const std::string &file_name);
		virtual const ALAudio *create_audio(const std::string &audio_name, const std::string &file_name);
		virtual const GLShader *get_shader(const std::string &shader_name) const;
		virtual const GLTexture *get_texture(const std::string &texture_name) const;
		virtual const ALAudio *get_audio(const std::string &audio_name) const;
		virtual void destroy_texture(const std::string &texture_name);
		virtual void destroy_audio(const std::string &audio_name);
		virtual void destroy_shader(const std::string &shader_name);
	};
}

#endif  // WATERY_RESOURCE_MANAGER_H
