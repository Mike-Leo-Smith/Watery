//
// Created by Mike Smith on 2017/5/28.
//

#include <cmath>
#include <iostream>
#include "helix_animation.h"

namespace watery
{
	void HelixAnimation::animate(Object *parent)
	{
		watery::Velocity *velocity = static_cast<watery::Velocity *>(parent->component("velocity"));
		float time = _timer.elapsed_time() * 1e-6f;
		
		velocity->set_vx(800 * sinf(time * 10) - 400);
		velocity->set_vy(500 * cosf(time * 10));
	}
}