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
		~GLShader(void);
		GLuint id(void) const { return _id; }
		void compile(const char *vertex_shader_source, const char *fragment_shader_source);
		void activate(void) const { glUseProgram(_id); }
		void set_uniform_int(const char *name, int val) const;
		void set_uniform_float(const char *name, float val) const;
		void set_uniform_mat4fv(const char *name, const float *mat4fv) const;
		void set_uniform_vec2f(const char *name, float v1, float v2) const;
		void set_uniform_vec3f(const char *name, float v1, float v2, float v3) const;
		void set_uniform_vec4f(const char *name, float v1, float v2, float v3, float v4) const;
		void set_uniform_vec4fv(const char *name, const float *vec4fv) const;
	};
}

#endif  // WATERY_GL_SHADER_H
