//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_PHYSICS_H
#define WATERY_PHYSICS_H

#include "shape.h"

namespace watery
{
	class Physics
	{
	public:
		static bool collision(const Shape &s1, const Vector &p1, const Shape &s2, const Vector &p2);
	};
}

#endif  // WATERY_PHYSICS_H
