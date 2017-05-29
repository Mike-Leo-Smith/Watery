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
		Circle(const Vector &center, float radius) : _center(center), _radius(radius), Shape("circle") {}
		Circle(float cx, float cy, float radius) : _center(cx, cy), _radius(radius), Shape("circle") {}
		virtual ~Circle(void) override {}
		virtual const Vector &center(void) const { return _center; }
		virtual float radius(void) const { return _radius; }
		virtual bool collided_with(const Shape &s2, const Vector &p1, const Vector &p2) const override;
	};
}

#endif  // WATERY_CIRCLE_H
