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
		bool _is_auto;
	public:
		Weapon(const std::string &weapon_type,bool is_auto)
				: Component("weapon"), _world(World::instance()), _timer(200000), _weapon_type(weapon_type),_is_auto(is_auto) {}
		virtual bool is_auto(void){return _is_auto;}
		virtual void fire(Object *owner);
		virtual ~Weapon(void) override {}
	};
}

#endif //WATERY_WEAPON_H
