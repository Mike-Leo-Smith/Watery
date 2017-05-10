//
// Created by Mike Smith on 2017/5/10.
//

#ifndef WATERY_SHAPE_H
#define WATERY_SHAPE_H

#include "../Mathematics/vector.h"

namespace watery
{
	enum ShapeType
	{
		SHAPE_UNDEFINED,
		SHAPE_RECTANGLE,
		SHAPE_CIRCLE
	};
	
	class Shape
	{
	private:
		ShapeType _type;
	
	public:
		Shape(ShapeType type = SHAPE_UNDEFINED) : _type(SHAPE_UNDEFINED) {}
		virtual ~Shape(void) {}
		virtual ShapeType type(void) const { return _type; }
		virtual bool collided_with(const Vector &p1, const Shape &s2, const Vector &p2) const = 0;
	};
}

#endif  // WATERY_SHAPE_H
