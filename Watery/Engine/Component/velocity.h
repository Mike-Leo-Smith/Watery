//
// Created by Mike Smith on 2017/4/19.
//

#ifndef WATERY_VELOCITY_H
#define WATERY_VELOCITY_H

#include "component.h"
#include "../../Data/Coord/coord.h"

namespace watery
{
	class Velocity : public Component
	{
	private:
		Coord _velocity;
	
	public:
		Velocity(const Coord &velocity = Coord()) : Component(COMPONENT_VELOCITY), _velocity(velocity) {}
		virtual ~Velocity(void) {}
		virtual const Coord &velocity(void) const { return _velocity; }
		virtual void set_velocity(const Coord &velocity) { _velocity = velocity; }
	};
};

#endif  // WATERY_VELOCITY_H
