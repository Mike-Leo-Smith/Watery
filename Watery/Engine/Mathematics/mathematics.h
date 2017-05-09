//
// Created by Mike Smith on 2017/5/7.
//

#ifndef WATERY_MATHEMATICS_H
#define WATERY_MATHEMATICS_H

#include "../../Data/Matrix/matrix.h"
#include "../../Data/Vector/vector.h"
#include "../../Data/Size/size.h"

namespace watery
{
	class Mathematics
	{
	public:
		virtual ~Mathematics(void) {}
		virtual const Matrix identity(void) const;
		virtual const Matrix translation(const Vector &position) const;
		virtual const Matrix scale(const Vector &scale) const;
		virtual const Matrix ortho_proj(const Vector &left_bottom_near, const Vector &right_top_far) const;
		virtual const Matrix persp_proj(const Vector &left_bottom_near, const Vector &right_top_far) const;
		virtual const Matrix ortho_proj(float left, float right, float bottom, float top, float near, float far) const;
		virtual const Matrix persp_proj(float fov, float aspect, float near, float far) const;
		virtual const Matrix camera_at(const Vector &position) const;
	};
}

#endif  // WATERY_MATHEMATICS_H
