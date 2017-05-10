//
// Created by Mike Smith on 2017/5/10.
//

#ifndef WATERY_POSITION_ANIMATION_H
#define WATERY_POSITION_ANIMATION_H

#include "component.h"
#include "../Mathematics/vector.h"
#include "../Timer/timer.h"

namespace watery
{
	class PositionAnimation : public Component
	{
	private:
		Timer _timer;
		Vector _offset;
		const Vector (*_func)(void);
	
	public:
		PositionAnimation(const Vector (*func)(void) = nullptr, Microsecond interval = 100000)
				: Component(COMPONENT_POSITION_ANIMATION), _timer(interval), _func(func) { _timer.reset(); }
		virtual ~PositionAnimation(void) {}
		virtual const Vector offset()
		{
			if (_timer.time_out() && _func != nullptr)
			{
				_offset = _func();
				_timer.reset();
			}
			
			return _offset;
		}
		virtual void set_func(const Vector (*func)(void)) { _func = func; }
	};
}

#endif  // WATERY_POSITION_ANIMATION_H
