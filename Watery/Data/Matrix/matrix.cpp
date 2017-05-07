//
// Created by Mike Smith on 2017/5/7.
//

#include <cstring>
#include "matrix.h"

namespace watery
{
	Matrix::Matrix(const float *data)
	{
		memmove((float *)_entries, data, 16);
	}
}