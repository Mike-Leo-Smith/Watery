//
// Created by Mike Smith on 2017/5/25.
//

#ifndef WATERY_ANIMATION_H
#define WATERY_ANIMATION_H

#include "component.h"
#include "../World/object.h"

namespace watery
{
	class Animation : public Component
	{
	public:
		Animation(void) : Component("animation") {}
		virtual ~Animation(void) override {}
		virtual void animate(Object *object) = 0;
	};
}

#endif  // WATERY_ANIMATION_H
