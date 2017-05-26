//
// Created by Mike Smith on 2017/5/7.
//

#include <cstdlib>
#include <sstream>
#include "component_factory.h"
#include "../Physics/shape.h"
#include "bounding_shape.h"

namespace watery
{
	void ComponentFactory::destroy_all(void)
	{
		for (auto &component : _components)
		{
			delete component;
		}
		_components.clear();
	}
	
	void ComponentFactory::destroy_component(Component *component)
	{
		delete component;
		_components.erase(component);
	}
	
	ComponentFactory &ComponentFactory::instance(void)
	{
		static ComponentFactory factory;
		return factory;
	}
	
	Component *ComponentFactory::create_component(const std::string &type, const std::string &res)
	{
		Component *component = nullptr;
		
		if (type == "position")
		{
			component = new Position(res);
		}
		else if (type == "velocity")
		{
			component = new Velocity(res);
		}
		else if (type == "audio")
		{
			ALAudio *al_audio = static_cast<ALAudio *>(_resource.get_resource("al_audio", res)->data());
			
			if (al_audio != nullptr)
			{
				component = new Audio(al_audio);
			}
		}
		else if (type == "shader")
		{
			GLShader *gl_shader = static_cast<GLShader *>(_resource.get_resource("gl_shader", res)->data());
			
			if (gl_shader != nullptr)
			{
				component = new Shader(gl_shader);
			}
		}
		else if (type == "texture")
		{
			GLTexture *gl_texture = static_cast<GLTexture *>(_resource.get_resource("gl_texture", res)->data());
			
			if (gl_texture != nullptr)
			{
				component = new Texture(gl_texture);
			}
		}
		else if (type == "vertex_array")
		{
			GLVertexArray *gl_vertex_array = static_cast<GLVertexArray *>(_resource.get_resource("gl_vertex_array", res)->data());
			
			if (gl_vertex_array != nullptr)
			{
				component = new VertexArray(gl_vertex_array);
			}
		}
		else if (type == "bounding_box")
		{
			Shape *shape = static_cast<Shape *>(_resource.get_resource("shape", res)->data());
			
			if (shape != nullptr)
			{
				component = new BoundingShape(shape);
			}
		}
		else if (type == "health")
		{
			float initial, maximum;
			std::stringstream buffer;
			
			buffer << res;
			buffer >> initial >> maximum;
			
			component = new Health(initial, maximum);
		}
		
		if (component != nullptr)
		{
			_components.insert(component);
		}
		
		return component;
	}
}