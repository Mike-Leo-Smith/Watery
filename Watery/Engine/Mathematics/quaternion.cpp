//
// Created by Mike Smith on 2017/5/7.
//

#include <cmath>
#include "quaternion.h"
#include "mathematics.h"

namespace watery
{
	float Quaternion::length(void) const
	{
		return sqrtf(_wxyz[0] * _wxyz[0] + _wxyz[1] * _wxyz[1] + _wxyz[2] * _wxyz[2] + _wxyz[3] * _wxyz[3]);
	}
	
	void Quaternion::normalize(void)
	{
		float len = length();
		
		_wxyz[0] /= len;
		_wxyz[1] /= len;
		_wxyz[2] /= len;
		_wxyz[3] /= len;
	}
	
	void Quaternion::set_wxyz(const float *wxyz)
	{
		for (int i = 0; i < 4; i++)
		{
			_wxyz[i] = wxyz[i];
		}
	}
	
	Quaternion::Quaternion(Vector axis, float angle)
	{
		float half_radians = Mathematics::radians(angle) * 0.5f;
		float cos_half = cosf(half_radians);
		float sin_half = sinf(half_radians);
		
		axis.normalize();
		
		_wxyz[0] = cos_half;
		_wxyz[1] = axis.x() * sin_half;
		_wxyz[2] = axis.y() * sin_half;
		_wxyz[3] = axis.z() * sin_half;
	}
	
	Quaternion::Quaternion(const Vector &axis_angles)
	{
		_wxyz[0] = 0.0f;
		_wxyz[1] = axis_angles.x();
		_wxyz[2] = axis_angles.y();
		_wxyz[3] = axis_angles.z();
	}
	
	const Quaternion Quaternion::inverse(void) const
	{
		float squared_norm_inv = 1 / (_wxyz[0] * _wxyz[0] + _wxyz[1] * _wxyz[1] + _wxyz[2] * _wxyz[2] + _wxyz[3] * _wxyz[3]);
		return Quaternion(_wxyz[0] * squared_norm_inv, _wxyz[1] * squared_norm_inv, _wxyz[2] * squared_norm_inv, _wxyz[3] * squared_norm_inv);
	}
	
	Quaternion &Quaternion::operator+=(const Quaternion &rhs)
	{
		_wxyz[0] += rhs._wxyz[0];
		_wxyz[1] += rhs._wxyz[1];
		_wxyz[2] += rhs._wxyz[2];
		_wxyz[3] += rhs._wxyz[3];
		
		return *this;
	}
	
	Quaternion &Quaternion::operator-=(const Quaternion &rhs)
	{
		_wxyz[0] -= rhs._wxyz[0];
		_wxyz[1] -= rhs._wxyz[1];
		_wxyz[2] -= rhs._wxyz[2];
		_wxyz[3] -= rhs._wxyz[3];
		
		return *this;
	}
	
	Quaternion &Quaternion::operator*=(const Quaternion &rhs)
	{
		Vector v1(_wxyz);
		Vector v2(_wxyz);
		
		float w = _wxyz[0] * rhs._wxyz[0] - dot(rhs);
		Vector v = rhs._wxyz[0] * v2 + _wxyz[0] * v1 + v2.cross(v1);
		
		_wxyz[0] = w;
		_wxyz[1] = v.x();
		_wxyz[2] = v.y();
		_wxyz[3] = v.z();
		
		return *this;
	}
	
	Quaternion &Quaternion::operator*=(float rhs)
	{
		_wxyz[0] *= rhs;
		_wxyz[1] *= rhs;
		_wxyz[2] *= rhs;
		_wxyz[3] *= rhs;
		
		return *this;
	}
	
	Quaternion &Quaternion::operator/=(float rhs)
	{
		float rhs_inv = 1.0f / rhs;
		
		_wxyz[0] *= rhs_inv;
		_wxyz[1] *= rhs_inv;
		_wxyz[2] *= rhs_inv;
		_wxyz[3] *= rhs_inv;
		
		return *this;
	}
	
	const Quaternion Quaternion::operator+(const Quaternion &rhs) const
	{
		Quaternion q = *this;
		
		q += rhs;
		return q;
	}
	
	const Quaternion Quaternion::operator-(const Quaternion &rhs) const
	{
		Quaternion q = *this;
		
		q -= rhs;
		return q;
	}
	
	const Quaternion Quaternion::operator*(const Quaternion &rhs) const
	{
		return cross(rhs);
	}
	
	const Quaternion Quaternion::operator*(float rhs) const
	{
		Quaternion q = *this;
		
		q *= rhs;
		return q;
	}
	
	const Quaternion Quaternion::operator/(float rhs) const
	{
		Quaternion q = *this;
		
		q /= rhs;
		return q;
	}
	
	const Quaternion operator*(float lhs, const Quaternion &rhs)
	{
		return rhs * lhs;
	}
	
	float Quaternion::dot(const Quaternion &rhs) const
	{
		return _wxyz[0] * rhs._wxyz[0] + _wxyz[1] * rhs._wxyz[1] + _wxyz[2] * rhs._wxyz[2] + _wxyz[3] * rhs._wxyz[3];
	}
	
	const Quaternion Quaternion::cross(const Quaternion &rhs) const
	{
		Vector v1(_wxyz[1], _wxyz[2], _wxyz[3]);
		Vector v2(_wxyz[1], _wxyz[2], _wxyz[3]);
		
		float w = _wxyz[0] * rhs._wxyz[0] - dot(rhs);
		Vector v = rhs._wxyz[0] * v2 + _wxyz[0] * v1 + v2.cross(v1);
		
		return Quaternion(w, v.x(), v.y(), v.z());
	}
	
	const Vector Quaternion::operator*(const Vector &rhs) const
	{
		float w2 = _wxyz[0] * _wxyz[0];
		Vector r(_wxyz[1], _wxyz[2], _wxyz[3]);
		
		return (w2 * w2 - 1.0f) * rhs + 2.0f * r.dot(rhs) * r + w2 * r.cross(rhs);
	}
}