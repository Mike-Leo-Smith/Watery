//
// Created by 97344 on 2017/5/29.
//

#include "random_move_animation.h"

namespace watery
{
	void RandomMoveAnimation::animate(std::shared_ptr<Object> parent)
	{
		if (parent->enabled("velocity"))
		{
			Velocity *velocity = static_cast<Velocity *>(parent->component("velocity"));
			
			if (_timer.time_out())
			{
				int acceleration_x = rand() % 500 - 250;
				int acceleration_y = rand() % 500 - 250;
				
				velocity->set_vx(acceleration_x);
				velocity->set_vy(acceleration_y);
				
				_timer.reset();
			}
		}
	}
}