//
// Created by Mike Smith on 2017/4/19.
//

#include "color.h"

namespace watery
{
	void Color::set_rgba(const float *rgba)
	{
		for (int i = 0; i < 4; i++)
		{
			_rgba[i] = rgba[i];
		}
	}
}