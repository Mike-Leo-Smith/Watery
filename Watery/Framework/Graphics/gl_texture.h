//
// Created by Mike Smith on 2017/4/19.
//

#ifndef WATERY_GL_TEXTURE_H
#define WATERY_GL_TEXTURE_H

#include <gl/glew.h>

namespace watery
{
	class GLTexture
	{
	private:
		GLuint _id;
	
	public:
		GLTexture(void) : _id(0) {}
		GLTexture(const unsigned char *image, GLsizei width, GLsizei height, GLsizei depth);
		virtual ~GLTexture(void);
		virtual GLuint id(void) const { return _id; }
		virtual void load(const unsigned char *image, GLsizei width, GLsizei height, GLsizei depth);
		virtual void activate(GLuint unit) const;
		
	};
}

#endif  // WATERY_GL_TEXTURE_H
