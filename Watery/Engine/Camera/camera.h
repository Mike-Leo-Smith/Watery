//
// Created by Mike Smith on 2017/4/25.
//

#ifndef WATERY_CAMERA_H
#define WATERY_CAMERA_H

/*
 *
 * | 1       |
 * |   1     |
 * |     1   |
 * |       1 |
 *
 */

#include "../../Data/Coord/coord.h"
#include "../../Data/Size/size.h"

namespace watery
{
	class Camera
	{
	private:
		Coord _position;
		float _mat[4][4];
	
	public:
		Camera(const Coord &postion = Coord(0, 0));
		void move(const Coord &direction);
		void move_x(float x);
		void move_y(float y);
		void move_z(float z);
		const float *mat(void) const { return (const float *)_mat; }
	};
}

#endif  // WATERY_CAMERA_H
