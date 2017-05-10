//
// Created by Mike Smith on 2017/4/17.
//

#include "physics.h"

namespace watery
{
	bool Physics::collision(const Shape &s1, const Vector &p1, const Shape &s2, const Vector &p2)
	{
		return s1.collided_with(p1, s2, p2);
	}
}