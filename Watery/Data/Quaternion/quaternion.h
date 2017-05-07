//
// Created by Mike Smith on 2017/5/7.
//

#ifndef WATERY_QUATERNION_H
#define WATERY_QUATERNION_H

#include <cstring>

namespace watery
{
	class Quaternion
	{
	private:
		float _wxyz[4];
	
	public:
		Quaternion(float w = 0, float x = 0, float y = 0, float z = 0) : _wxyz { w, x, y, z } {}
		Quaternion(const float *wxyz) { memmove(_wxyz, wxyz, 4); }
		~Quaternion(void) {}
		float length(void) const;
		void normalize(void);
		float w(void) const { return _wxyz[0]; }
		float x(void) const { return _wxyz[1]; }
		float y(void) const { return _wxyz[2]; }
		float z(void) const { return _wxyz[3]; }
		const float *wxyz(void) const { return _wxyz; }
		void set_w(float w) { _wxyz[0] = w; }
		void set_x(float x) { _wxyz[1] = x; }
		void set_y(float y) { _wxyz[2] = y; }
		void set_z(float z) { _wxyz[3] = z; }
		void set_wxyz(const float *wxyz) { memmove(_wxyz, wxyz, 4); }
	};
}

#endif  // WATERY_QUATERNION_H
