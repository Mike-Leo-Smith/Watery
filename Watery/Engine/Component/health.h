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
		float _maximum;
		float _health;
	
	public:
		Health(float initial, float maximum)
				: Component("health"), _health(initial <= maximum ? initial : maximum), _maximum(maximum) {}
		virtual ~Health(void) override {}
		virtual float health(void) const { return _health; }
		virtual float maximum(void) const { return _maximum; }
		virtual void set_health(float health) { _health = (health <= _maximum ? (health >= 0 ? health : 0) : _maximum); }
		virtual void set_maximum(float maximum) { _maximum = maximum, _health = (_health <= maximum ? _health : _maximum); }
		virtual void increase(float val) { _health = (_health + val <= _maximum ? _health + val : _maximum); }
		virtual void decrease(float val) { _health = (_health - val >= 0 ? _health - val : 0); }
		virtual bool dying(void) const { return _health <= 1e-3; }
	};
}

#endif  // WATERY_HEALTH_H
