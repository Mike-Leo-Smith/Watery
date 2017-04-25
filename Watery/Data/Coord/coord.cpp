//
// Created by Mike Smith on 2017/4/17.
//

#include "coord.h"

namespace watery
{
	Coord &Coord::operator+=(const Coord &rhs)
	{
		_xyz[0] += rhs._xyz[0];
		_xyz[1] += rhs._xyz[1];
		_xyz[2] += rhs._xyz[2];
		
		return *this;
	}
	
	Coord &Coord::operator-=(const Coord &rhs)
	{
		_xyz[0] -= rhs._xyz[0];
		_xyz[1] -= rhs._xyz[1];
		_xyz[2] -= rhs._xyz[2];
		
		return *this;
	}
}