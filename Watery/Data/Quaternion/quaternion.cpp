//
// Created by Mike Smith on 2017/5/7.
//

#include <cmath>
#include "quaternion.h"

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
}