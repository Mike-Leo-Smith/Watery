//
// Created by Mike Smith on 2017/4/19.
//

#include <iostream>
#include "gl_shader.h"

namespace watery
{
	GLShader::GLShader(const char *vertex_shader_source, const char *fragment_shader_source) : _id(0)
	{
		compile(vertex_shader_source, fragment_shader_source);
	}
	
	void GLShader::compile(const char *vertex_shader_source, const char *fragment_shader_source)
	{
		GLint success;
		GLchar info[512];
		
		GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
		glCompileShader(vertex_shader);
		
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertex_shader, 512, nullptr, info);
			std::cerr << info << std::endl;
		}
		
		GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
		glCompileShader(fragment_shader);
		
		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragment_shader, 512, nullptr, info);
			std::cerr << info << std::endl;
		}
		
		glDeleteProgram(_id);
		_id = glCreateProgram();
		glAttachShader(_id, vertex_shader);
		glAttachShader(_id, fragment_shader);
		glLinkProgram(_id);
		
		glGetProgramiv(_id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(_id, 512, nullptr, info);
			std::cerr << info << std::endl;
		}
		
		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);
	}
	
	GLShader::~GLShader(void)
	{
		glDeleteProgram(_id);
	}
	
	void GLShader::set_uniform_int(const char *name, int val) const
	{
		GLint uniform = glGetUniformLocation(_id, name);
		glUniform1i(uniform, val);
	}
	
	void GLShader::set_uniform_float(const char *name, float val) const
	{
		GLint uniform = glGetUniformLocation(_id, name);
		glUniform1f(uniform, val);
	}
	
	void GLShader::set_uniform_mat4fv(const char *name, const float *mat4fv) const
	{
		GLint uniform = glGetUniformLocation(_id, name);
		glUniformMatrix4fv(uniform, 1, GL_FALSE, mat4fv);
	}
	
	void GLShader::set_uniform_vec4fv(const char *name, const float *vec4fv) const
	{
		GLint uniform = glGetUniformLocation(_id, name);
		glUniform4fv(uniform, 1, vec4fv);
	}
	
	void GLShader::set_uniform_vec4f(const char *name, float v1, float v2, float v3, float v4) const
	{
		GLint uniform = glGetUniformLocation(_id, name);
		glUniform4f(uniform, v1, v2, v3, v4);
	}
	
	void GLShader::set_uniform_vec2f(const char *name, float v1, float v2) const
	{
		GLint uniform = glGetUniformLocation(_id, name);
		glUniform2f(uniform, v1, v2);
	}
	
	void GLShader::set_uniform_vec3f(const char *name, float v1, float v2, float v3) const
	{
		GLint uniform = glGetUniformLocation(_id, name);
		glUniform3f(uniform, v1, v2, v3);
	}
}