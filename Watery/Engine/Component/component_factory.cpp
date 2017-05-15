//
// Created by Mike Smith on 2017/5/7.
//

#include "component_factory.h"

namespace watery
{
	void ComponentFactory::destroy_all(void)
	{
		for (auto &item : _components)
		{
			destroy(item);
		}
	}
	
	void ComponentFactory::destroy(Component *component)
	{
		delete component;
		_components.erase(component);
	}
	
	ComponentFactory &ComponentFactory::instance(void)
	{
		static ComponentFactory factory;
		return factory;
	}
	
	Position *ComponentFactory::create_position(const Vector &coord)
	{
		Position *position = new Position(coord);
		
		_components.insert((Position *)position);
		return position;
	}
	
	Velocity *ComponentFactory::create_velocity(const Vector &coord)
	{
		Velocity *velocity = new Velocity(coord);
		
		_components.insert((Velocity *)velocity);
		return velocity;
	}
	
	Audio *ComponentFactory::create_audio(ALAudio *al_audio)
	{
		Audio *audio = new Audio(al_audio);
		_components.insert((Audio *)audio);
		return audio;
	}
	
	Shader *ComponentFactory::create_shader(GLShader *gl_shader)
	{
		Shader *shader = new Shader(gl_shader);
		
		_components.insert((Shader *)shader);
		return shader;
	}
	
	Texture *ComponentFactory::create_texture(GLTexture *gl_texture)
	{
		Texture *texture = new Texture(gl_texture);
		
		_components.insert((Texture *)texture);
		return texture;
	}
}