//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_COORD_H
#define WATERY_COORD_H

#include <cstring>

namespace watery
{
	class Coord
	{
	private:
		float _xyz[3];
	
	public:
		Coord(float x = 0, float y = 0, float z = 0) : _xyz{x, y, z} {}
		Coord(float *xyz) { memmove(_xyz, xyz, 3); }
		virtual ~Coord(void) {}
		virtual float x(void) const { return _xyz[0]; }
		virtual float y(void) const { return _xyz[1]; }
		virtual float z(void) const { return _xyz[2]; }
		virtual const float *xyz(void) const { return _xyz; }
		virtual void set_x(float x) { _xyz[0] = x; }
		virtual void set_y(float y) { _xyz[1] = y; }
		virtual void set_z(float z) { _xyz[2] = z; }
		virtual void set_xyz(const float *xyz) { memmove(_xyz, xyz, 3); }
	};
}

#endif  // WATERY_COORD_H
