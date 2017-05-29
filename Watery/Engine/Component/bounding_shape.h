//
// Created by Mike Smith on 2017/5/26.
//

#ifndef WATERY_BOUNDING_SHAPE_H
#define WATERY_BOUNDING_SHAPE_H

#include "../Physics/shape.h"
#include "component.h"

namespace watery
{
	class BoundingShape : public Component
	{
	private:
		Shape *_shape;
	
	public:
		BoundingShape(Shape *shape = nullptr) : Component("bounding_shape"), _shape(shape) {}
		virtual ~BoundingShape(void) override {}
		virtual Shape *shape(void) { return _shape; }
		virtual const Shape *shape(void) const { return _shape; }
		virtual void bind_shape(Shape *shape) { _shape = shape; }
	};
}

#endif  // WATERY_BOUNDING_SHAPE_H
