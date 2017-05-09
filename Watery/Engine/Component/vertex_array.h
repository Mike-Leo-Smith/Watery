//
// Created by Mike Smith on 2017/5/8.
//

#ifndef WATERY_VERTEX_ARRAY_H
#define WATERY_VERTEX_ARRAY_H

#include "../../Framework/Graphics/gl_vertex_array.h"
#include "component.h"

namespace watery
{
	class VertexArray : public Component
	{
	private:
		const GLVertexArray *_vertex_array;
	
	public:
		VertexArray(const GLVertexArray *vertex_array = nullptr)
				: Component(COMPONENT_VERTEX_ARRAY), _vertex_array(vertex_array) {}
		virtual ~VertexArray(void) {}
		virtual const GLVertexArray *vertex_array(void) const { return _vertex_array; }
		virtual void bind(const GLVertexArray *vertex_array) { _vertex_array = vertex_array; }
	};
}

#endif  // WATERY_VERTEX_ARRAY_H
