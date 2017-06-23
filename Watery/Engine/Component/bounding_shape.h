/// @file bounding_shape.h
/// @brief Header file for class BoundingShape.
/// @author ZSK
/// @date May 26, 2017

#ifndef WATERY_BOUNDING_SHAPE_H
#define WATERY_BOUNDING_SHAPE_H

#include "component.h"
#include "../../Framework/Physics/shape.h"

namespace watery
{
	/// @brief Bounding shape component for objects.
	/// @note This component is used for collision detections.
	/// @see Component
	/// @see Object
	class BoundingShape : public Component
	{
	private:
		/// @brief Pointer to the shape.
		/// @see Shape
		Shape *_shape;
	
	public:
		/// @brief Construct from the pointer to shape resource.
		/// @param shape The pointer to the shape.
		/// @see Shape
		/// @see Component
		/// @see ComponentFactory
		/// @see Object
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		BoundingShape(Shape *shape = nullptr) : Component("bounding_shape"), _shape(shape) {}
		
		/// @brief Destructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see Object
		/// @see ComponentFactory
		virtual ~BoundingShape(void) override {}
		
		/// @breif Get the pointer to the shape that is bound to the component,
		/// @return Pointer to the shape bound to the component,
		/// @see Shape
		virtual Shape *shape(void) { return _shape; }
		
		/// @brief Get the const pointer to the shape that is bound to the component,
		/// @return Const pointer to the shape bound to the component,
		/// @see Shape
		virtual const Shape *shape(void) const { return _shape; }
		
		/// @breif Bind a shape to the component.
		/// @param shape Pointer to the shape to bind.
		/// @see Shape
		virtual void bind_shape(Shape *shape) { _shape = shape; }
	};
}

#endif  // WATERY_BOUNDING_SHAPE_H
