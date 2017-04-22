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
		if (_id != 0)
		{
			glDeleteProgram(_id);
		}
		
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
		if (_id != 0)
		{
			glDeleteProgram(_id);
		}
	}
	
	void GLShader::set_uniform_int(const char *name, int val)
	{
		GLint uniform = glGetUniformLocation(_id, name);
		
		if (uniform != 0)
		{
			glUniform1i(uniform, val);
		}
		else
		{
			std::cerr << "Cannot find the uniform..." << std::endl;
		}
	}
	
	void GLShader::set_uniform_float(const char *name, float val)
	{
		GLint uniform = glGetUniformLocation(_id, name);
		
		if (uniform != 0)
		{
			glUniform1f(uniform, val);
		}
		else
		{
			std::cerr << "Cannot find the uniform..." << std::endl;
		}
	}
	
	void GLShader::set_uniform_mat4fv(const char *name, const float *mat4fv)
	{
		GLint uniform = glGetUniformLocation(_id, name);
		
		if (uniform != 0)
		{
			glUniformMatrix4fv(uniform, 1, GL_FALSE, mat4fv);
		}
		else
		{
			std::cerr << "Cannot find the uniform..." << std::endl;
		}
	}
}