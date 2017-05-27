//
// Created by Mike Smith on 2017/5/7.
//

#include <cstdlib>
#include <sstream>
#include "component_factory.h"
#include "../Physics/shape.h"
#include "bounding_shape.h"
#include "rotation.h"
#include "angular_velocity.h"

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
	
	Component *ComponentFactory::create_component(const std::string &type, const std::string &arg)
	{
		Component *component = nullptr;
		
		if (type == "position")
		{
			float x, y, z;
			std::stringstream buffer;
			
			buffer << arg;
			buffer >> x >> y >> z;
			
			component = new Position(Vector(x, y, z));
		}
		else if (type == "velocity")
		{
			float vx, vy, vz;
			std::stringstream buffer;
			
			buffer << arg;
			buffer >> vx >> vy >> vz;
			
			component = new Velocity(Vector(vx, vy, vz));
		}
		else if (type == "rotation")
		{
			float axis_x, axis_y, axis_z, angle;
			std::stringstream buffer;
			
			buffer << arg;
			buffer >> axis_x >> axis_y >> axis_z >> angle;
			
			component = new Rotation(Vector(axis_x, axis_y, axis_z), angle);
		}
		else if (type == "angular_velocity")
		{
			component = new AngularVelocity((float)atof(arg.c_str()));
		}
		else if (type == "audio")
		{
			ALAudio *al_audio = static_cast<ALAudio *>(_resource.get_resource("al_audio", arg)->data());
			
			if (al_audio != nullptr)
			{
				component = new Audio(al_audio);
			}
		}
		else if (type == "shader")
		{
			GLShader *gl_shader = static_cast<GLShader *>(_resource.get_resource("gl_shader", arg)->data());
			
			if (gl_shader != nullptr)
			{
				component = new Shader(gl_shader);
			}
		}
		else if (type == "texture")
		{
			GLTexture *gl_texture = static_cast<GLTexture *>(_resource.get_resource("gl_texture", arg)->data());
			
			if (gl_texture != nullptr)
			{
				component = new Texture(gl_texture);
			}
		}
		else if (type == "vertex_array")
		{
			GLVertexArray *gl_vertex_array = static_cast<GLVertexArray *>(_resource.get_resource("gl_vertex_array", arg)->data());
			
			if (gl_vertex_array != nullptr)
			{
				component = new VertexArray(gl_vertex_array);
			}
		}
		else if (type == "bounding_shape")
		{
			Shape *shape = static_cast<Shape *>(_resource.get_resource("shape", arg)->data());
			
			if (shape != nullptr)
			{
				component = new BoundingShape(shape);
			}
		}
		else if (type == "health")
		{
			float initial, maximum;
			std::stringstream buffer;
			
			buffer << arg;
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