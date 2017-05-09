//
// Created by Mike Smith on 2017/4/18.
//

#ifndef WATERY_CLOCK_H
#define WATERY_CLOCK_H

#include <chrono>

namespace watery
{
	typedef time_t Microsecond;
	
	class Clock
	{
	private:
		std::chrono::high_resolution_clock _clock;
		static Clock *_instance;
		
		Clock(void) {}
		Clock(const Clock &) = delete;
		Clock(Clock &&) = delete;
		Clock &operator=(const Clock &) = delete;
		~Clock(void) {}
		
	public:
		Microsecond time(void) const { return std::chrono::duration_cast<std::chrono::microseconds>(_clock.now().time_since_epoch()).count(); }
		static Clock &instance(void) { return *_instance; }
	};
}

#endif  // WATERY_CLOCK_H
