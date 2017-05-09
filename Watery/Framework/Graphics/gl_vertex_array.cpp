//
// Created by Mike Smith on 2017/4/19.
//

#include "gl_vertex_array.h"

namespace watery
{
	GLVertexArray::GLVertexArray(const float *vertices, GLsizei size, GLsizei elements)
			: _vao(0), _vbo(0), _elements(elements)
	{
		load(vertices, size, elements);
	}
	
	GLVertexArray::~GLVertexArray(void)
	{
		glDeleteVertexArrays(1, &_vao);
		glDeleteBuffers(1, &_vbo);
	}
	
	void GLVertexArray::load(const float *vertices, GLsizei size, GLsizei elements)
	{
		glGenBuffers(1, &_vbo);
		glGenVertexArrays(1, &_vao);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		
		_elements = elements;
	}
	
	void GLVertexArray::activate(void) const
	{
		glBindVertexArray(_vao);
	}
	
	void GLVertexArray::set_pointers(GLuint index, GLuint size, GLuint stride, GLuint offset)
	{
		glBindVertexArray(_vao);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (GLvoid *)(offset * sizeof(GLfloat)));
		glEnableVertexAttribArray(index);
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
