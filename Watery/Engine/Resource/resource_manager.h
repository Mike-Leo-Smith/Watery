//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_RESOURCE_MANAGER_H
#define WATERY_RESOURCE_MANAGER_H

#include <map>
#include <string>
#include "../System/system.h"
#include "../../Framework/Audio/al_audio.h"
#include "../../Framework/Graphics/gl_texture.h"
#include "../../Framework/Graphics/gl_shader.h"
#include "../../Framework/Graphics/gl_vertex_array.h"

namespace watery
{
	class ResourceManager
	{
	private:
		std::map<std::string, ALAudio *> _audios;
		std::map<std::string, GLTexture *> _textures;
		std::map<std::string, GLShader *> _shaders;
		std::map<std::string, GLVertexArray *> _vertex_arrays;
		static ResourceManager *_instance;
		
		ResourceManager(void) {}
		ResourceManager(const ResourceManager &) = delete;
		ResourceManager(ResourceManager &&) = delete;
		ResourceManager &operator=(const ResourceManager &) = delete;
		~ResourceManager(void);
	
	public:
		static ResourceManager &instance(void) { return *_instance; }
		GLShader *get_shader(const std::string &shader_name, const std::string &vertex_shader_file_name = "", const std::string &fragment_shader_file_name = "");
		GLTexture *get_texture(const std::string &texture_name, const std::string &file_name = "");
		GLVertexArray *get_vertex_array(const std::string &vertex_array_name, const std::string &vertex_array_file);
		ALAudio *get_audio(const std::string &audio_name, const std::string &file_name = "");
		void destroy_texture(const std::string &texture_name);
		void destroy_audio(const std::string &audio_name);
		void destroy_shader(const std::string &shader_name);
	};
}

#endif  // WATERY_RESOURCE_MANAGER_H
