//
// Created by Mike Smith on 2017/4/25.
//

#include "camera.h"

namespace watery
{
	Camera::Camera(const Vector &position)
	{
		// Setting up the position component.
		bind_component(_factory.create_position(position));
	}
	
	void Camera::move(const Vector &direction)
	{
		Position *position = component(COMPONENT_POSITION)->decode<Position>();
		
		if (position != nullptr)
		{
			position->move(direction);
		}
	}
	
	void Camera::move_x(float dx)
	{
		Position *position = component(COMPONENT_POSITION)->decode<Position>();
		
		if (position != nullptr)
		{
			position->move_x(dx);
		}
	}
	
	void Camera::move_y(float dy)
	{
		Position *position = component(COMPONENT_POSITION)->decode<Position>();
		
		if (position != nullptr)
		{
			position->move_y(dy);
		}
	}
	
	void Camera::move_z(float dz)
	{
		Position *position = component(COMPONENT_POSITION)->decode<Position>();
		
		if (position != nullptr)
		{
			position->move_z(dz);
		}
	}
	
	const Vector Camera::position(void) const
	{
		const Position *pos = component(COMPONENT_POSITION)->decode<Position>();
		
		if (pos != nullptr)
		{
			return pos->position();
		}
		else
		{
			return Vector();
		}
	}
	
	Camera::~Camera(void)
	{
		delete component(COMPONENT_POSITION);
	}
}