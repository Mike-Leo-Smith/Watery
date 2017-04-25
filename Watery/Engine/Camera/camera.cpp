//
// Created by Mike Smith on 2017/4/25.
//

#include "camera.h"

namespace watery
{
	Camera::Camera(const Coord &postion) : _position(postion)
	{
		// Clear.
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				_mat[i][j] = 0;
			}
		}
		
		// Identity.
		_mat[0][0] = 1.0f;
		_mat[1][1] = 1.0f;
		_mat[2][2] = 1.0f;
		_mat[3][3] = 1.0f;
		
		// Translation.
		_mat[3][0] = -_position.x();
		_mat[3][1] = -_position.y();
		_mat[3][2] = -_position.z();
	}
	
	void Camera::move(const Coord &direction)
	{
		_position += direction;
		_mat[3][0] = -_position.x();
		_mat[3][1] = -_position.y();
		_mat[3][2] = -_position.z();
	}
	
	void Camera::move_x(float x)
	{
		_position.set_x(_position.x() + x);
		_mat[3][0] -= x;
	}
	
	void Camera::move_y(float y)
	{
		_position.set_y(_position.y() + y);
		_mat[3][1] -= y;
	}
	
	void Camera::move_z(float z)
	{
		_position.set_z(_position.z() + z);
		_mat[3][2] -= z;
	}
}