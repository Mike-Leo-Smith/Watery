//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_COORD_H
#define WATERY_COORD_H

namespace watery
{
	class Coord
	{
	private:
		float _x;
		float _y;
		float _z;
	
	public:
		Coord(float x = 0, float y = 0, float z = 0) : _x(x), _y(y), _z(z) {}
	};
}

#endif  // WATERY_COORD_H
