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
		GLTexture(void) { glGenTextures(1, &_id); }
		GLTexture(const unsigned char *image, GLsizei width, GLsizei height, GLsizei depth);
		~GLTexture(void);
		GLuint id(void) const { return _id; }
		void load(const unsigned char *image, GLsizei width, GLsizei height, GLsizei depth);
		void activate(GLuint unit) const;
	};
}

#endif  // WATERY_GL_TEXTURE_H
