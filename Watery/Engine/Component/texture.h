//
// Created by Mike Smith on 2017/4/19.
//

#ifndef WATERY_TEXTURE_H
#define WATERY_TEXTURE_H

#include "../../Framework/Graphics/gl_texture.h"
#include "component.h"

namespace watery
{
	class Texture : public Component
	{
	private:
		GLTexture *_texture;
	
	public:
		Texture(void) : Component(COMPONENT_TEXTURE) {}
	};
}

#endif  // WATERY_TEXTURE_H
