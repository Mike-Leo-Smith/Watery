//
// Created by Mike Smith on 2017/5/5.
//

#ifndef WATERY_TEXTURE_H
#define WATERY_TEXTURE_H

#include "component.h"
#include "../../Framework/Graphics/gl_texture.h"

namespace watery
{
	class Texture : public Component
	{
	private:
		GLTexture *_texture;
		
	public:
		Texture(GLTexture *texture = nullptr) : Component(COMPONENT_TEXTURE), _texture(texture) {}
		virtual ~Texture(void) {}
		virtual void bind_texture(GLTexture *texture) { _texture = texture; }
		virtual const GLTexture *texture(void) const { return _texture; }
		virtual GLTexture *texture(void) { return _texture; }
	};
}

#endif  // WATERY_TEXTURE_H
