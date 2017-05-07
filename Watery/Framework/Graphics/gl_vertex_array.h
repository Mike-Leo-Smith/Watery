//
// Created by Mike Smith on 2017/4/19.
//

#ifndef WATERY_GL_VERTEX_ARRAY_H
#define WATERY_GL_VERTEX_ARRAY_H

#include <gl/glew.h>

namespace watery
{
	class GLVertexArray
	{
	private:
		GLuint _vbo;
		GLuint _vao;
	
	public:
		GLVertexArray(void) : _vao(0), _vbo(0) {}
		GLVertexArray(const float *vertices, GLsizei size);
		~GLVertexArray(void);
		void load(const float *vertices, GLsizei size);
		void activate(void) const;
		void set_pointers(GLuint index, GLuint size, GLuint stride, GLuint pointer_offset);
	};
}

#endif  // WATERY_GL_VERTEX_ARRAY_H
