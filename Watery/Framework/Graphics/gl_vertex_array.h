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
		GLsizei _count;
		GLenum _type;
	
	public:
		GLVertexArray(void) : _vao(0), _vbo(0), _count(0) {}
		GLVertexArray(const float *vertices, GLsizei size, GLsizei count, GLenum type);
		~GLVertexArray(void);
		GLsizei count(void) const { return _count; }
		void load(const float *vertices, GLsizei size);
		void activate(void) const;
		void set_pointers(GLuint index, GLuint size, GLuint stride, GLuint offset);
		void set_type(GLenum type) { _type = type; }
		void set_count(GLsizei count) { _count = count; }
		GLenum type(void) const { return _type; }
	};
}

#endif  // WATERY_GL_VERTEX_ARRAY_H
