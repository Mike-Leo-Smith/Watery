//
// Created by Mike Smith on 2017/5/7.
//

#ifndef WATERY_COMPONENT_FACTORY_H
#define WATERY_COMPONENT_FACTORY_H

#include <set>
#include "position.h"
#include "velocity.h"
#include "audio.h"
#include "shader.h"
#include "texture.h"
#include "vertex_array.h"
#include "health.h"
#include "../Resource/resource_manager.h"

namespace watery
{
	class ComponentFactory
	{
	private:
		std::set<Component *> _components;
		ResourceManager &_resource;
		
		ComponentFactory(void) : _resource(ResourceManager::instance()) {}
		ComponentFactory(const ComponentFactory &) = delete;
		ComponentFactory(ComponentFactory &&) = delete;
		ComponentFactory &operator=(const ComponentFactory &) = delete;
		~ComponentFactory(void) { destroy_all(); }
	
	public:
		Position *create_position(const Vector &coord);
		Velocity *create_velocity(const Vector &coord);
		Audio *create_audio(ALAudio *al_audio);
		Shader *create_shader(GLShader *gl_shader);
		Texture *create_texture(GLTexture *gl_texture);
		VertexArray *create_vertex_array(GLVertexArray *gl_vertex_array);
		Component *create_component(const std::string &type, const std::string &arg);
		void destroy_component(Component *component);
		void destroy_all(void);
		static ComponentFactory &instance(void);
	};
}

#endif  // WATERY_COMPONENT_FACTORY_H
