//
// Created by 97344 on 2017/5/29.
//

#ifndef WATERY_RANDOM_MOVE_ANIMATION_H
#define WATERY_RANDOM_MOVE_ANIMATION_H

#include <random>
#include "animation.h"
#include "../Timer/timer.h"

namespace watery
{
	class RandomMoveAnimation : public Animation
	{
	private:
		Timer _timer;
		int _acceleration_x, _acceleration_y;
	
	public:
		RandomMoveAnimation() { _timer.set_time_out(1000000); }
		virtual ~RandomMoveAnimation(void) override {}
		virtual void animate(std::shared_ptr<Object> parent) override;
		
	};
}

#endif // WATERY_RANDOM_MOVE_ANIMATION_H
