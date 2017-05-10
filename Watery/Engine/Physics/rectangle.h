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
		virtual bool collided_with(const Vector &p1, const Shape &s2, const Vector &p2) const override;
	};
}

#endif  // WATERY_RECTANGLE_H
