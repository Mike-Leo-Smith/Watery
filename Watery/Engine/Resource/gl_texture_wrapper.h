//
// Created by Mike Smith on 2017/5/25.
//

#ifndef WATERY_GL_TEXTURE_WRAPPER_H
#define WATERY_GL_TEXTURE_WRAPPER_H

#include "resource_wrapper.h"
#include "../../Framework/Graphics/gl_texture.h"

namespace watery
{
	class GLTextureWrapper : public ResourceWrapper
	{
	private:
		GLTexture *_texture;
	
	public:
		GLTextureWrapper(const std::string &file_name);
		virtual ~GLTextureWrapper(void) override { delete _texture; }
		virtual void *data(void) override { return _texture; }
	};
}

#endif  // WATERY_GL_TEXTURE_WRAPPER_H
