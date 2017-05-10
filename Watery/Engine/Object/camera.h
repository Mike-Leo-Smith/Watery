//
// Created by Mike Smith on 2017/4/25.
//

#ifndef WATERY_CAMERA_H
#define WATERY_CAMERA_H

#include "../Mathematics/vector.h"
#include "object.h"

namespace watery
{
	class Camera : public Object
	{
	public:
		Camera(const Vector &position = Vector());
		virtual ~Camera(void);
		virtual const Vector position(void) const;
		virtual void move(const Vector &direction);
		virtual void move_x(float dx);
		virtual void move_y(float dy);
		virtual void move_z(float dz);
		virtual float x(void) const;
		virtual float y(void) const;
		virtual float z(void) const;
	};
}

#endif  // WATERY_CAMERA_H
