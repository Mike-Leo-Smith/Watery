//
// Created by 97344 on 2017/5/29.
//

#include "RandomMoveAnimation.h"

namespace watery
{
	void RandomMoveAnimation::animate(std::shared_ptr<Object> parent)
	{
		watery::Velocity *velocity = static_cast<Velocity *>(parent->component("velocity"));
		//Microsecond time = _timer.elapsed_time();
		//
		//if (rand() * 1000 < time)
		//{
		//	_acceleration_x = rand() % 500 - 250;
		//	_acceleration_y = rand() % 500 - 250;
		//	velocity->set_vx(_acceleration_x);
		//	velocity->set_vy(_acceleration_y);
		//	_timer.reset();
		//}
		
		if (_timer.time_out())
		{
			_acceleration_x = rand() % 500 - 250;
			_acceleration_y = rand() % 500 - 250;
			velocity->set_vx(_acceleration_x);
			velocity->set_vy(_acceleration_y);
			_timer.reset();
		}
	}
}