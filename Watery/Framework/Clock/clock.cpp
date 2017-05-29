//
// Created by Mike Smith on 2017/4/18.
//

#include "clock.h"

namespace watery
{
	Clock &Clock::instance(void)
	{
		static Clock clock;
		return clock;
	}
}