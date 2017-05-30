//
// Created by 97344 on 2017/5/29.
//

#include "AI_position_animation.h"
#include <cmath>


namespace watery
{
	void AI_position_animation::animate(Object *parent)
	{
		watery::Velocity *velocity = static_cast<watery::Velocity *>(parent->component("velocity"));
		int time = _timer.elapsed_time();
		if(rand()*300<time)
		{
			_acceleration_x=rand()%400-200;
			_acceleration_y=rand()%400-200;
			_timer.reset();
		}
		velocity->set_vx(_acceleration_x);
		velocity->set_vy(_acceleration_y);
	}
}