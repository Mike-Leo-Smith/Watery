//
// Created by Mike Smith on 2017/5/25.
//

#ifndef WATERY_GL_VERTEX_ARRAY_WRAPPER_H
#define WATERY_GL_VERTEX_ARRAY_WRAPPER_H

#include "../../Framework/Graphics/gl_vertex_array.h"
#include "resource_wrapper.h"

namespace watery
{
	class GLVertexArrayWrapper : public ResourceWrapper
	{
	private:
		GLVertexArray *_vertex_array;
	
	public:
		GLVertexArrayWrapper(const std::string &file_name);
		virtual ~GLVertexArrayWrapper(void) override { delete _vertex_array; }
		virtual void *data(void) override { return _vertex_array; }
	};
}

#endif  // WATERY_GL_VERTEX_ARRAY_WRAPPER_H
