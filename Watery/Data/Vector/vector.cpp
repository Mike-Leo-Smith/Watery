//
// Created by Mike Smith on 2017/4/17.
//

#include <cmath>
#include "vector.h"

namespace watery
{
	float Vector::length(void) const
	{
		return sqrtf(_xyz[0] * _xyz[0] + _xyz[1] * _xyz[1] + _xyz[2] * _xyz[2]);
	}
	
	void Vector::normalize(void)
	{
		float len = length();
		
		_xyz[0] /= len;
		_xyz[1] /= len;
		_xyz[2] /= len;
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
		return Vector(_xyz[0] + rhs._xyz[1], _xyz[1] + rhs._xyz[1], _xyz[2] + rhs._xyz[2]);
	}
	
	const Vector Vector::operator-(const Vector &rhs) const
	{
		return Vector(_xyz[0] - rhs._xyz[1], _xyz[1] - rhs._xyz[1], _xyz[2] - rhs._xyz[2]);
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
}