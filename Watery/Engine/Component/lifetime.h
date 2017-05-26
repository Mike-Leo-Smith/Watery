//
// Created by Mike Smith on 2017/5/26.
//

#ifndef WATERY_LIFETIME_H
#define WATERY_LIFETIME_H

#include "component.h"
#include "../Timer/timer.h"

namespace watery
{
	class Lifetime : public Component
	{
	private:
		Timer _timer;
	
	public:
		Lifetime(Microsecond life) : Component("lifetime"), _timer(life) {}
		virtual ~Lifetime(void) override {}
		virtual void born(void) { _timer.reset(); }
		virtual bool dead(void) { return _timer.time_out(); }
	};
}

#endif  // WATERY_LIFETIME_H
