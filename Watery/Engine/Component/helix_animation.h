//
// Created by Mike Smith on 2017/5/28.
//

#ifndef WATERY_HELIX_ANIMATION_H
#define WATERY_HELIX_ANIMATION_H

#include "animation.h"
#include "../Timer/timer.h"

namespace watery
{
	class HelixAnimation : public Animation
	{
	private:
		Timer _timer;
	
	public:
		virtual void animate(Object *parent) override;
	};
}

#endif  // WATERY_HELIX_ANIMATION_H
