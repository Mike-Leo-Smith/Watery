//
// Created by Mike Smith on 2017/5/26.
//

#ifndef WATERY_ANGULAR_VELOCITY_H
#define WATERY_ANGULAR_VELOCITY_H

#include "component.h"

namespace watery
{
	class AngularVelocity : public Component
	{
	private:
		float _omega;
	
	public:
		AngularVelocity(float omega) : Component("angular_velocity"), _omega(omega) {}
		virtual ~AngularVelocity(void) {}
		virtual float omega(void) const { return _omega; }
		virtual void set_omega(float omega) { _omega = omega; }
		virtual void accelerate(float delta) { _omega += delta; }
	};
}

#endif  // WATERY_ANGULAR_VELOCITY_H
