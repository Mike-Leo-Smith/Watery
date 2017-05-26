//
// Created by Mike Smith on 2017/5/7.
//

#ifndef WATERY_MATHEMATICS_H
#define WATERY_MATHEMATICS_H

#include "matrix.h"
#include "vector.h"
#include "quaternion.h"

namespace watery
{
	class Mathematics
	{
	public:
		static const Matrix identity(void);
		static const Matrix translation(const Vector &position);
		static const Matrix rotation(const Vector &axis, const Vector &angle);
		static const Matrix scale(float s);
		static const Matrix scale(const Vector &scale);
		static const Matrix ortho_proj(const Vector &left_bottom_near, const Vector &right_top_far);
		static const Matrix persp_proj(const Vector &left_bottom_near, const Vector &right_top_far);
		static const Matrix ortho_proj(float left, float right, float bottom, float top, float near, float far);
		static const Matrix persp_proj(float fov, float aspect, float near, float far);
		static const Matrix camera_at(const Vector &position);
	};
}

#endif  // WATERY_MATHEMATICS_H
