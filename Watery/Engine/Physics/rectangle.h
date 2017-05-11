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
				: _left_bottom(left_bottom), _right_top(right_top) {}
		Rectangle(float left, float bottom, float right, float top)
				: _left_bottom(left, bottom), _right_top(right, top) {}
		virtual ~Rectangle(void) {}
		virtual bool collided_with(const Vector &p1, const Shape &s2, const Vector &p2) const override;
	};
}

#endif  // WATERY_RECTANGLE_H
