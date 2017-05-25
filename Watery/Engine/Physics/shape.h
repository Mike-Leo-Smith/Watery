//
// Created by Mike Smith on 2017/5/10.
//

#ifndef WATERY_SHAPE_H
#define WATERY_SHAPE_H

#include <string>
#include "../Mathematics/vector.h"

namespace watery
{
	class Shape
	{
	private:
		std::string _type;
	
	public:
		Shape(const std::string &type = "undefined") : _type(type) {}
		virtual ~Shape(void) {}
		virtual const std::string &type(void) const { return _type; }
		virtual bool collided_with(const Vector &p1, const Shape &s2, const Vector &p2) const = 0;
	};
}

#endif  // WATERY_SHAPE_H
