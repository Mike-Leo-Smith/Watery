//
// Created by Mike Smith on 2017/5/25.
//

#include <fstream>
#include <sstream>
#include "gl_shader_wrapper.h"

namespace watery
{
	GLShaderWrapper::GLShaderWrapper(const std::string &file_name) : ResourceWrapper("gl_shader"), _shader(nullptr)
	{
		size_t colon_pos = file_name.find(':');
		
		std::string vertex_shader_file_name = file_name.substr(0, colon_pos);
		std::string fragment_shader_file_name = file_name.substr(colon_pos + 1);
		
		std::ifstream vertex_shader_file;
		std::ifstream fragment_shader_file;
		
		vertex_shader_file.open(vertex_shader_file_name);
		fragment_shader_file.open(fragment_shader_file_name);
		
		if (vertex_shader_file.is_open() && fragment_shader_file.is_open())
		{
			std::stringstream vertex_shader_code_stream;
			std::stringstream fragment_shader_code_stream;
			
			vertex_shader_code_stream << vertex_shader_file.rdbuf();
			fragment_shader_code_stream << fragment_shader_file.rdbuf();
			
			std::string vertex_shader_code;
			std::string fragment_shader_code;
			
			vertex_shader_code = vertex_shader_code_stream.str();
			fragment_shader_code = fragment_shader_code_stream.str();
			
			_shader = new GLShader(vertex_shader_code.c_str(), fragment_shader_code.c_str());
		}
	}
}