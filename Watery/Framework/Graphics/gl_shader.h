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
		virtual void set_uniform_int(const char *name, int val) const;
		virtual void set_uniform_float(const char *name, float val) const;
		virtual void set_uniform_mat4fv(const char *name, const float *mat4fv) const;
		virtual void set_uniform_vec2f(const char *name, float v1, float v2) const;
		virtual void set_uniform_vec3f(const char *name, float v1, float v2, float v3) const;
		virtual void set_uniform_vec4f(const char *name, float v1, float v2, float v3, float v4) const;
		virtual void set_uniform_vec4fv(const char *name, const float *vec4fv) const;
	};
}

#endif  // WATERY_GL_SHADER_H
