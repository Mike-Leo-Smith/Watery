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
			
			bool left;
			bool right;
			bool top;
			bool bottom;
			bool middle;
			
			//left
			if ((circle.center() + p2).y() < (_left_bottom + p1).y())
			{
				left = ((circle.center() + p2) - (_left_bottom + p1)).length() <= circle.radius();
			}
			else if ((circle.center() + p2).y() > (_right_top + p1).y())
			{
				left = ((circle.center() + p2) - (left_top() + p1)).length() <= circle.radius();
			}
			else
			{
				left = fabs(((circle.center() + p2) - (_left_bottom + p1)).x()) <= circle.radius();
			}
			//right
			if ((circle.center() + p2).y() < (_left_bottom + p1).y())
			{
				right = ((circle.center() + p2) - (right_bottom() + p1)).length() <= circle.radius();
			}
			else if ((circle.center() + p2).y() > (_right_top + p1).y())
			{
				right = ((circle.center() + p2) - (_right_top + p1)).length() <= circle.radius();
			}
			else
			{
				right = fabs(((circle.center() + p2) - (_right_top + p1)).x()) <= circle.radius();
			}
			//top
			if ((circle.center() + p2).x() < (_left_bottom + p1).x())
			{
				top = ((circle.center() + p2) - (left_top() + p1)).length() <= circle.radius();
			}
			else if ((circle.center() + p2).x() > (_right_top + p1).x())
			{
				top = ((circle.center() + p2) - (_right_top + p1)).length() <= circle.radius();
			}
			else
			{
				top = fabs(((circle.center() + p2) - (_right_top + p1)).y()) <= circle.radius();
			}
			//bottom
			if ((circle.center() + p2).x() < (_left_bottom + p1).x())
			{
				bottom = ((circle.center() + p2) - (_left_bottom + p1)).length() <= circle.radius();
			}
			else if ((circle.center() + p2).x() > (_right_top + p1).x())
			{
				bottom = ((circle.center() + p2) - (right_bottom() + p1)).length() <= circle.radius();
			}
			else
			{
				bottom = fabs(((circle.center() + p2) - (_left_bottom + p1)).y()) <= circle.radius();
			}
			//middle
			middle = (((circle.center() + p2).x() - (_left_bottom + p1).x()) > circle.radius())
			         && (((_right_top + p1).x() - (circle.center() + p2).x()) > circle.radius())
			         && (((circle.center() + p2).y() - (_left_bottom + p1).y()) > circle.radius())
			         && (((_right_top + p1).y() - (circle.center() + p2).y()) > circle.radius());
			
			//std::cout << "*****" << std::endl << left << right << top << bottom << middle << std::endl << "*****" << std::endl;
			
			collided = left || right || top || bottom || middle;
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