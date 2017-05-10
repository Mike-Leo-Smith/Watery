//
// Created by Mike Smith on 2017/5/7.
//

#include <cmath>
#include "mathematics.h"

namespace watery
{
	const Matrix Mathematics::identity(void)
	{
		const float entries[] =
				{
						1, 0, 0, 0,
						0, 1, 0, 0,
						0, 0, 1, 0,
						0, 0, 0, 1
				};
		
		return Matrix(entries);
	}
	
	const Matrix Mathematics::translation(const Vector &position)
	{
		float x = position.x();
		float y = position.y();
		float z = position.z();
		
		// Note that the data is in column index.
		// So the actual matrix is...
		// [ 1  0  0  x ]
		// [ 0  1  0  y ]
		// [ 0  0  1  z ]
		// [ 0  0  0  1 ]
		float entries[] =
				{
						1, 0, 0, 0,
						0, 1, 0, 0,
						0, 0, 1, 0,
						x, y, z, 1
				};
		
		return Matrix(entries);
	}
	
	const Matrix Mathematics::scale(const Vector &scale)
	{
		float w = scale.x();
		float h = scale.y();
		float d = scale.z();
		
		float entries[] =
				{
						w, 0, 0, 0,
						0, h, 0, 0,
						0, 0, d, 0,
						0, 0, 0, 1
				};
		
		return Matrix(entries);
	}
	
	const Matrix Mathematics::ortho_proj(const Vector &left_bottom_near, const Vector &right_top_far)
	{
		float l = left_bottom_near.x();
		float b = left_bottom_near.y();
		float n = left_bottom_near.z();
		float r = right_top_far.x();
		float t = right_top_far.y();
		float f = right_top_far.z();
		
		// [ 2/(r-l)        0         0  -(r+l)/(r-l) ]
		// [       0  2/(t-b)         0  -(t+b)/(t-b) ]
		// [       0        0  -2/(f-n)  -(f+n)/(f-n) ]
		// [       0        0         0             1 ]
		float entries[] =
				{
						2 / (r - l), 0, 0, 0,
						0, 2 / (t - b), 0, 0,
						0, 0, -2 / (f - n), 0,
						-(r + l) / (r - l), -(t + b) / (t - b), -(f + n) / (f - n), 1
				};
		
		return Matrix(entries);
	}
	
	const Matrix Mathematics::camera_at(const Vector &position)
	{
		float x = position.x();
		float y = position.y();
		float z = position.z();
		
		// [ 1  0  0  -x ]
		// [ 0  1  0  -y ]
		// [ 0  0  1  -z ]
		// [ 0  0  0   1 ]
		float entries[] =
				{
						1, 0, 0, 0,
						0, 1, 0, 0,
						0, 0, 1, 0,
						-x, -y, -z, 1
				};
		
		return Matrix(entries);
	}
	
	const Matrix Mathematics::persp_proj(const Vector &left_bottom_near, const Vector &right_top_far)
	{
		float l = left_bottom_near.x();
		float b = left_bottom_near.y();
		float n = left_bottom_near.z();
		float r = right_top_far.x();
		float t = right_top_far.y();
		float f = right_top_far.z();
		
		// [ 2n/(r-l)         0   (r+l)/(r-l)           0 ]
		// [        0  2n/(t-b)   (t+b)/(t-b)           0 ]
		// [        0         0  -(f+n)/(f-n)  -2fn/(f-n) ]
		// [        0         0            -1           0 ]
		float entries[] =
				{
						2 * n / (r - l), 0, 0, 0,
						0, 2 * n / (t - b), 0, 0,
						(r + l) / (r - l), (t + b) / (t - b), -(f + n) / (f - n), -1,
						0, 0, -2 * f * n / (f - n), 0
				};
		
		return Matrix(entries);
	}
	
	const Matrix Mathematics::ortho_proj(float left, float right, float bottom, float top, float near, float far)
	{
		return ortho_proj(Vector(left, bottom, near), Vector(right, top, far));
	}
	
	const Matrix Mathematics::persp_proj(float fov, float aspect, float near, float far)
	{
		float tan_half_fov = tanf(fov * (float)M_PI / 180 / 2);
		float tan_half_aspect = tanf(aspect * (float)M_PI / 180 / 2);
		
		Vector left_bottom_near(-tan_half_aspect, -tan_half_fov, near);
		Vector right_top_far(tan_half_aspect, tan_half_fov, far);
		
		return persp_proj(left_bottom_near, right_top_far);
	}
	
	const Matrix Mathematics::scale(float s)
	{
		float entries[] =
				{
						s, 0, 0, 0,
						0, s, 0, 0,
						0, 0, s, 0,
						0, 0, 0, 1
				};
		
		return Matrix(entries);
	}
}
