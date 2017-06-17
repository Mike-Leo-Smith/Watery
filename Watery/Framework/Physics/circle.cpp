//
// Created by Mike Smith on 2017/5/11.
//

#include "circle.h"

namespace watery
{
	bool Circle::collided_with(const Shape &s2, const Vector &p1, const Vector &p2) const
	{
		bool collided = false;
		
		if (s2.type() == "circle")
		{
			const Circle &circle = static_cast<const Circle &>(s2);
			collided = (p1 + _center - p2 - circle._center).length() <= (_radius + circle._radius);
		}
		else if (s2.type() == "rectangle")
		{
			collided = s2.collided_with(*this, p2, p1);
		}
		
		return collided;
	}
}
