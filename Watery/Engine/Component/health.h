//
// Created by Mike Smith on 2017/5/10.
//

#ifndef WATERY_HEALTH_H
#define WATERY_HEALTH_H

#include "component.h"

namespace watery
{
	class Health : public Component
	{
	private:
		float _health;
	
	public:
		Health(float initial) : Component("health"), _health(initial) {}
		virtual ~Health(void) override {}
		virtual float health(void) const { return _health; }
		virtual void set_health(float health) { _health = health; }
	};
}

#endif  // WATERY_HEALTH_H
