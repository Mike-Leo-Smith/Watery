//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_RESOURCE_H
#define WATERY_RESOURCE_H

#include <map>
#include <string>
#include "../System/system.h"
#include "../../Framework/Audio/al_audio.h"
#include "../../Framework/Graphics/gl_texture.h"
#include "../../Framework/Graphics/gl_shader.h"

namespace watery
{
	class Resource
	{
	private:
		std::map<std::string, ALAudio *> _audios;
		std::map<std::string, GLTexture *> _textures;
		std::map<std::string, GLShader *> _shaders;
		static Resource *_instance;
		
		Resource(void) {}
		Resource(const Resource &) = delete;
		Resource &operator=(const Resource &) = delete;
		virtual ~Resource(void);
	
	public:
		static Resource &instance(void) { return *_instance; }
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

#endif  // WATERY_RESOURCE_H
