//
// Created by Mike Smith on 2017/5/11.
//

#ifndef WATERY_CIRCLE_H
#define WATERY_CIRCLE_H

#include "shape.h"

namespace watery
{
	class Circle : public Shape
	{
	private:
		Vector _center;
		float _radius;
	
	public:
		Circle(const Vector &center, float radius) : _center(center), _radius(radius) {}
		Circle(float cx, float cy, float radius) : _center(cx, cy), _radius(radius) {}
		virtual ~Circle(void) {}
		virtual bool collided_with(const Vector &p1, const Shape &s2, const Vector &p2) const override;
	};
}

#endif  // WATERY_CIRCLE_H
