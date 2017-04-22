//
// Created by Mike Smith on 2017/4/19.
//

#include "gl_vertex_array.h"

namespace watery
{
	GLVertexArray::GLVertexArray(const float *vertices, GLsizei size) : _vao(0), _vbo(0)
	{
		load(vertices, size);
	}
	
	GLVertexArray::~GLVertexArray(void)
	{
		if (_vao != 0)
		{
			glDeleteVertexArrays(1, &_vao);
		}
		
		if (_vbo != 0)
		{
			glDeleteBuffers(1, &_vbo);
		}
	}
	
	void GLVertexArray::load(const float *vertices, GLsizei size)
	{
		if (_vao != 0)
		{
			glDeleteVertexArrays(1, &_vao);
		}
		
		if (_vbo != 0)
		{
			glDeleteBuffers(1, &_vbo);
		}
		
		glGenBuffers(1, &_vbo);
		glGenVertexArrays(1, &_vao);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	void GLVertexArray::activate(void) const
	{
		glBindVertexArray(_vao);
	}
	
	void GLVertexArray::set_pointers(GLuint index, GLuint size, GLuint stride, GLuint pointer_offset)
	{
		glBindVertexArray(_vao);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (GLvoid *)(pointer_offset * sizeof(GLfloat)));
		glEnableVertexAttribArray(index);
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}