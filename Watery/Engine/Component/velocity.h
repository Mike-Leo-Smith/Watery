//
// Created by Mike Smith on 2017/4/19.
//

#ifndef WATERY_VELOCITY_H
#define WATERY_VELOCITY_H

#include "component.h"
#include "../Mathematics/vector.h"

namespace watery
{
	class Velocity : public Component
	{
	private:
		Vector _velocity;
	
	public:
		Velocity(const Vector &velocity = Vector()) : Component(COMPONENT_VELOCITY), _velocity(velocity) {}
		virtual ~Velocity(void) {}
		virtual const Vector &velocity(void) const { return _velocity; }
		virtual void set_velocity(const Vector &velocity) { _velocity = velocity; }
	};
};

#endif  // WATERY_VELOCITY_H
