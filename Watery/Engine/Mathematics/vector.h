//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_VECTOR_H
#define WATERY_VECTOR_H

#include <cstring>
#include <string>

namespace watery
{
	class Vector
	{
	private:
		float _xyz[3];
	
	public:
		Vector(float x = 0, float y = 0, float z = 0) : _xyz { x, y, z } {}
		Vector(float *xyz) { set_xyz(xyz); }
		~Vector(void) {}
		float length(void) const;
		void normalize(void);
		const Vector cross(const Vector &rhs) const;
		float dot(const Vector &rhs) const;
		float x(void) const { return _xyz[0]; }
		float y(void) const { return _xyz[1]; }
		float z(void) const { return _xyz[2]; }
		const float *xyz(void) const { return _xyz; }
		void set_x(float x) { _xyz[0] = x; }
		void set_y(float y) { _xyz[1] = y; }
		void set_z(float z) { _xyz[2] = z; }
		void set(int pos, float x) { _xyz[pos] = x; }
		void set_xyz(const float *xyz);
		
		Vector &operator*=(float rhs);
		Vector &operator/=(float rhs);
		Vector &operator+=(const Vector &rhs);
		Vector &operator-=(const Vector &rhs);
		const Vector operator+(const Vector &rhs) const;
		const Vector operator-(const Vector &rhs) const;
		float operator*(const Vector &rhs) const;
		const Vector operator*(float rhs) const;
		friend const Vector operator*(float lhs, const Vector rhs) { return rhs * lhs; }
		const Vector operator/(float rhs) const;
		const Vector operator+(void) const { return *this; }
		const Vector operator-(void) const { return Vector(-_xyz[0], -_xyz[1], -_xyz[2]); }
	};
}

#endif  // WATERY_VECTOR_H
