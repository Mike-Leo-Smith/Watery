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
		virtual float vx(void) const { return _velocity.x(); }
		virtual float vy(void) const { return _velocity.y(); }
		virtual float vz(void) const { return _velocity.z(); }
		virtual void set_vx(float vx) { _velocity.set_x(vx); }
		virtual void set_vy(float vy) { _velocity.set_y(vy); }
		virtual void set_vz(float vz) { _velocity.set_z(vz); }
		virtual void accelerate(const Vector &a) { _velocity += a; }
		virtual void accelerate_x(float ax) { _velocity.set_x(_velocity.x() + ax); }
		virtual void accelerate_y(float ay) { _velocity.set_y(_velocity.y() + ay); }
		virtual void accelerate_z(float az) { _velocity.set_z(_velocity.z() + az); }
	};
};

#endif  // WATERY_VELOCITY_H
