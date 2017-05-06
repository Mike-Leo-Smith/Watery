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
	public:
		virtual ~ComponentFactory(void) {}
		virtual Position *create_position(const Coord &coord) const { return new Position(coord); }
		virtual Velocity *create_velocity(const Coord &coord) const { return new Velocity(coord); }
		virtual Audio *create_audio(const ALAudio *audio) const { return new Audio(audio); }
		virtual Shader *create_shader(const GLShader *shader) const { return new Shader(shader); }
		virtual Texture *create_texture(const GLTexture *texture) const { return new Texture(texture); }
	};
}

#endif  // WATERY_COMPONENT_FACTORY_H
