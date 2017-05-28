//
// Created by 97344 on 2017/5/27.
//

#ifndef WATERY_WEAPON_H
#define WATERY_WEAPON_H

#include "component.h"
#include "../Scene/world.h"
#include "../Timer/timer.h"

namespace watery
{
	class Weapon : public Component
	{
	protected:
		World &_world;
		std::string _weapon_type;
		static int _bullet_count;
		float _angle, _velocity;
		Timer _timer;
	
	public:
		Weapon(const std::string &weapon_type)
				: Component("weapon"), _world(World::instance()), _timer(3), _weapon_type(weapon_type) {}
		void fire(Object *owner);
		virtual ~Weapon(void) override {}
	};
}

#endif //WATERY_WEAPON_H
