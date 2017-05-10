//
// Created by Mike Smith on 2017/5/7.
//

#ifndef WATERY_COMPONENT_FACTORY_H
#define WATERY_COMPONENT_FACTORY_H

#include "position.h"
#include "velocity.h"
#include "audio.h"
#include "shader.h"
#include "texture.h"

namespace watery
{
	class ComponentFactory
	{
	private:
		ComponentFactory(void) {}
		ComponentFactory(const ComponentFactory &) = delete;
		ComponentFactory(ComponentFactory &&) = delete;
		ComponentFactory &operator=(const ComponentFactory &) = delete;
		~ComponentFactory(void) {}
	
	public:
		Position *create_position(const Vector &coord) const { return new Position(coord); }
		Velocity *create_velocity(const Vector &coord) const { return new Velocity(coord); }
		Audio *create_audio(ALAudio *audio) const { return new Audio(audio); }
		Shader *create_shader(GLShader *shader) const { return new Shader(shader); }
		Texture *create_texture(GLTexture *texture) const { return new Texture(texture); }
		static ComponentFactory &instance(void);
	};
}

#endif  // WATERY_COMPONENT_FACTORY_H
