//
// Created by Mike Smith on 2017/4/17.
//

#include <cmath>
#include "vector.h"
#include "mathematics.h"

namespace watery
{
	float Vector::length(void) const
	{
		return sqrtf(_xyz[0] * _xyz[0] + _xyz[1] * _xyz[1] + _xyz[2] * _xyz[2]);
	}
	
	void Vector::normalize(void)
	{
		float len_inv = 1.0f / length();
		
		_xyz[0] *= len_inv;
		_xyz[1] *= len_inv;
		_xyz[2] *= len_inv;
	}
	
	Vector &Vector::operator+=(const Vector &rhs)
	{
		_xyz[0] += rhs._xyz[0];
		_xyz[1] += rhs._xyz[1];
		_xyz[2] += rhs._xyz[2];
		
		return *this;
	}
	
	Vector &Vector::operator-=(const Vector &rhs)
	{
		_xyz[0] -= rhs._xyz[0];
		_xyz[1] -= rhs._xyz[1];
		_xyz[2] -= rhs._xyz[2];
		
		return *this;
	}
	
	const Vector Vector::operator+(const Vector &rhs) const
	{
		return Vector(_xyz[0] + rhs._xyz[0], _xyz[1] + rhs._xyz[1], _xyz[2] + rhs._xyz[2]);
	}
	
	const Vector Vector::operator-(const Vector &rhs) const
	{
		return Vector(_xyz[0] - rhs._xyz[0], _xyz[1] - rhs._xyz[1], _xyz[2] - rhs._xyz[2]);
	}
	
	Vector &Vector::operator*=(float rhs)
	{
		_xyz[0] *= rhs;
		_xyz[1] *= rhs;
		_xyz[2] *= rhs;
		
		return *this;
	}
	
	Vector &Vector::operator/=(float rhs)
	{
		_xyz[0] /= rhs;
		_xyz[1] /= rhs;
		_xyz[2] /= rhs;
		
		return *this;
	}
	
	float Vector::operator*(const Vector &rhs) const
	{
		return (_xyz[0] * rhs._xyz[0] + _xyz[1] * rhs._xyz[1] + _xyz[2] * rhs._xyz[2]);
	}
	
	const Vector Vector::operator*(float rhs) const
	{
		return Vector(_xyz[0] * rhs, _xyz[1] * rhs, _xyz[2] * rhs);
	}
	
	const Vector Vector::operator/(float rhs) const
	{
		return Vector(_xyz[0] / rhs, _xyz[1] / rhs, _xyz[2] / rhs);
	}
	
	void Vector::set_xyz(const float *xyz)
	{
		for (int i = 0; i < 3; i++)
		{
			_xyz[i] = xyz[i];
		}
	}
	
	const Vector Vector::cross(const Vector &rhs) const
	{
		float x1 = _xyz[0];
		float y1 = _xyz[1];
		float z1 = _xyz[2];
		float x2 = rhs._xyz[0];
		float y2 = rhs._xyz[1];
		float z2 = rhs._xyz[2];
		
		float i = y1 * z2 - z1 * y2;
		float j = z1 * x2 - x1 * z2;
		float k = x1 * y2 - y1 * x2;
		
		return Vector(i, j, k);
	}
	
	float Vector::dot(const Vector &rhs) const
	{
		return *this * rhs;
	}
	
	float Vector::longitude(void) const
	{
		return Mathematics::degrees(atanf(_xyz[2] / _xyz[0]));
	}
	
	float Vector::latitude(void) const
	{
		return Mathematics::degrees(asinf(_xyz[1] / length()));
	}
}
