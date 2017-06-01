//
// Created by Mike Smith on 2017/5/31.
//

#ifndef WATERY_SHRINK_ANIMATION_H
#define WATERY_SHRINK_ANIMATION_H

#include "animation.h"
#include "../Timer/timer.h"

namespace watery
{
	class ShrinkAnimation : public Animation
	{
	private:
		Timer _timer;
	
	public:
		ShrinkAnimation(void) : _timer(30000) {}
		virtual ~ShrinkAnimation(void) override {}
		virtual void animate(std::shared_ptr<Object> parent) override;
	};
}

#endif  // WATERY_SHRINK_ANIMATION_H
