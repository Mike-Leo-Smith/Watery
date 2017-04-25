//
// Created by Mike Smith on 2017/4/19.
//

#include "gl_texture.h"

namespace watery
{
	GLTexture::~GLTexture(void)
	{
		glDeleteTextures(1, &_id);
	}
	
	void GLTexture::activate(GLuint unit) const
	{
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, _id);
	}
	
	GLTexture::GLTexture(const unsigned char *image, GLsizei width, GLsizei height, GLsizei depth)
	{
		glGenTextures(1, &_id);
		load(image, width, height, depth);
	}
	
	void GLTexture::load(const unsigned char *image, GLsizei width, GLsizei height, GLsizei depth)
	{
		glBindTexture(GL_TEXTURE_2D, _id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
		if (depth == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		}
		else
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		}
		
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}