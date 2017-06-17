//
// Created by Mike Smith on 2017/4/18.
//

#ifndef WATERY_TIMER_H
#define WATERY_TIMER_H

#include "../../Framework/Clock/clock.h"

namespace watery
{
	class Timer
	{
	private:
		Clock &_clock;
		Microsecond _start;
		Microsecond _time_out;
		
	public:
		Timer(Microsecond time_out = 0) : _clock(Clock::instance()), _time_out(time_out) { _start = _clock.time(); }
		virtual ~Timer(void) {}
		virtual void reset(void) { _start = _clock.time(); }
		virtual bool time_out(void) const { return (_time_out != 0) && (_clock.time() - _start > _time_out); }
		virtual void set_time_out(Microsecond time_out) { _time_out = time_out, _start = _clock.time(); }
		virtual Microsecond elapsed_time(void) const { return _clock.time() - _start; }
	};
}

#endif  // WATERY_TIMER_H
