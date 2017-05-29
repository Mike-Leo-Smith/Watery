//
// Created by 97344 on 2017/5/29.
//

#ifndef WATERY_AI_POSITION_ANIMATION_H
#define WATERY_AI_POSITION_ANIMATION_H
#include <random>
#include "animation.h"
#include "../Timer/timer.h"

namespace watery
{
	class AI_position_animation:public Animation
	{
	private:
		Timer _timer;
		int _acceleration_x, _acceleration_y;
	public:
		AI_position_animation()
		{
			_acceleration_x=rand()%400-200;
			_acceleration_y=rand()%400-200;
		}
		virtual void animate(Object *parent) override;
		
		
	};
}



#endif //WATERY_AI_POSITION_ANIMATION_H
