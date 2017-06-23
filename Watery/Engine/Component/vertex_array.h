/// @file vertex_array.h
/// @brief Header file for class VertexArray.
/// @author ZSK
/// @date May 8, 2017

#ifndef WATERY_VERTEX_ARRAY_H
#define WATERY_VERTEX_ARRAY_H

#include "../../Framework/Graphics/gl_vertex_array.h"
#include "component.h"

namespace watery
{
	/// @brief Vertex array component for objects.
	/// @see Object
	/// @see Component
	class VertexArray : public Component
	{
	private:
		/// @brief Pointer to OpenGL vertex array resource.
		/// @see GLVertexArray
		GLVertexArray *_vertex_array;
	
	public:
		/// @brief Construct from a pointer to OpenGL vertex array.
		/// @param vertex_array Pointer to OpenGL vertex array.
		/// @see Object
		/// @see ComponentFactory
		/// @see GLVertexArray
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		VertexArray(GLVertexArray *vertex_array = nullptr)
				: Component("vertex_array"), _vertex_array(vertex_array) {}
		
		/// @brief Destructor.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual ~VertexArray(void) override {}
		
		/// @brief Get const pointer to OpenGL vertex array.
		/// @return Const pointer to OpenGL vertex array.
		virtual const GLVertexArray *vertex_array(void) const { return _vertex_array; }
		
		/// @brief Get pointer to OpenGL vertex array.
		/// @return Pointer to OpenGL vertex array.
		virtual GLVertexArray *vertex_array(void) { return _vertex_array; }
		
		/// @brief Bind to a pointer to OpenGL vertex array.
		/// @param vertex_array Pointer to OpenGL vertex array to bind.
		virtual void bind(GLVertexArray *vertex_array) { _vertex_array = vertex_array; }
	};
}

#endif  // WATERY_VERTEX_ARRAY_H
