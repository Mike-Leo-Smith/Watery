//
// Created by Mike Smith on 2017/4/19.
//

#ifndef WATERY_GL_SHADER_H
#define WATERY_GL_SHADER_H

#include <gl/glew.h>

namespace watery
{
	class GLShader
	{
	private:
		GLuint _id;
		
	public:
		GLShader(void) : _id(0) {}
		GLShader(const char *vertex_shader_source, const char *fragment_shader_source);
		GLuint id(void) const { return _id; }
		void compile(const char *vertex_shader_source, const char *fragment_shader_source);
		void activiate(void) const { glUseProgram(_id); }
	};
}

#endif  // WATERY_GL_SHADER_H
