//
// Created by Mike Smith on 2017/5/25.
//

#include <fstream>
#include <vector>
#include "gl_vertex_array_wrapper.h"

namespace watery
{
	GLVertexArrayWrapper::GLVertexArrayWrapper(const std::string &file_name)
			: ResourceWrapper("gl_vertex_array"), _vertex_array(nullptr)
	{
		std::ifstream file(file_name);
		
		if (file.is_open())
		{
			std::string s;
			
			_vertex_array = new GLVertexArray;
			
			while (!file.eof())
			{
				file >> s;
				
				if (s == "#")
				{
					break;
				}
				
				if (s == ">")
				{
					GLuint index;
					GLuint size;
					GLuint stride;
					GLuint offset;
					
					// Read pointer attributes.
					file >> index >> size >> stride >> offset;
					_vertex_array->set_pointers(index, size, stride, offset);
				}
				else if (s == "{")
				{
					GLsizei count = 0;
					std::vector<float> vertices;
					
					file >> s;
					while (s != "}")
					{
						if (s == ".")
						{
							file >> count;
						}
						else
						{
							vertices.push_back((float)atof(s.c_str()));
						}
						file >> s;
					}
					_vertex_array->load(vertices.data(), (GLsizei)vertices.size());
					_vertex_array->set_count(count);
				}
			}
		}
	}
}