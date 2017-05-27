//
// Created by Mike Smith on 2017/5/10.
//

#include <cmath>
#include "rectangle.h"
#include "circle.h"

namespace watery
{
	bool Rectangle::collided_with(const Shape &s2, const Vector &p1, const Vector &p2) const
	{
		bool collided = false;
		
		if (s2.type() == "circle")
		{
			const Circle &circle = static_cast<const Circle &>(s2);
			
			collided = !(fabs((circle.center() + p2 - p1 - _left_bottom).x()) > circle.radius()
			             && fabs((circle.center() + p2 - p1 - _left_bottom).y()) > circle.radius()
			             && fabs((circle.center() + p2 - p1 - _right_top).x()) > circle.radius()
			             && fabs((circle.center() + p2 - p1 - _right_top).y()) > circle.radius());
		}
		else if (s2.type() == "rectangle")
		{
			const Rectangle &rectangle = static_cast<const Rectangle &>(s2);
			
			collided = !(((rectangle._right_top + p2).x()) < (_left_bottom + p1).x()
			             || ((rectangle._left_bottom + p2).x()) > (_right_top + p1).x()
			             || ((rectangle._left_bottom + p2).y()) > (_right_top + p1).y()
			             || ((rectangle._right_top + p2).y()) < (_left_bottom + p1).y());
		}
		
		return collided;
	}
}