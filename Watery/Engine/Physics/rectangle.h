//
// Created by Mike Smith on 2017/5/10.
//

#ifndef WATERY_RECTANGLE_H
#define WATERY_RECTANGLE_H

#include "shape.h"
#include "../Mathematics/vector.h"

namespace watery
{
	class Rectangle : public Shape
	{
	private:
		Vector _left_bottom;
		Vector _right_top;
	
	public:
		Rectangle(const Vector &left_bottom, const Vector &right_top)
				: _left_bottom(left_bottom), _right_top(right_top), Shape("rectangle") {}
		Rectangle(float left, float bottom, float right, float top)
				: _left_bottom(left, bottom), _right_top(right, top), Shape("rectangle") {}
		virtual ~Rectangle(void) override {}
		virtual bool collided_with(const Shape &s2, const Vector &p1, const Vector &p2) const override;
		virtual const Vector &left_bottom(void) const { return _left_bottom; }
		virtual const Vector &right_top(void) const { return _right_top; }
		virtual const Vector left_top(void) const { return Vector(_left_bottom.x(), _right_top.y()); }
		virtual const Vector right_bottom(void) const { return Vector(_right_top.x(), _left_bottom.y()); }
	};
}

#endif  // WATERY_RECTANGLE_H
