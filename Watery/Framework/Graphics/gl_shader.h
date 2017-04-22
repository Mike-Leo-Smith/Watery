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
		virtual ~GLShader(void);
		virtual GLuint id(void) const { return _id; }
		virtual void compile(const char *vertex_shader_source, const char *fragment_shader_source);
		virtual void activate(void) const { glUseProgram(_id); }
		virtual void set_uniform_int(const char *name, int val);
		virtual void set_uniform_float(const char *name, float val);
		virtual void set_uniform_mat4fv(const char *name, const float *mat4fv);
	};
}

#endif  // WATERY_GL_SHADER_H
