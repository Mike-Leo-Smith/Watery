//
// Created by Mike Smith on 2017/5/31.
//

#include "shrink_animation.h"
#include "scale.h"

namespace watery
{
	void ShrinkAnimation::animate(Object *parent)
	{
		if (_timer.time_out())
		{
			if (!parent->enabled("scale"))
			{
				parent->create_component("scale", "1");
			}
			
			Scale *scale = static_cast<Scale *>(parent->component("scale"));
			
			scale->multiply(0.7);
			if (scale->scale() < 0.1)
			{
				parent->create_component("lifetime", "1");
			}
			_timer.reset();
		}
	}
}