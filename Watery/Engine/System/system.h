//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_SYSTEM_H
#define WATERY_SYSTEM_H

#include "../Message/messenger.h"

namespace watery
{
	constexpr Microsecond SYSTEM_DEFAULT_UPDATE_INTERVAL = 5000;
	
	class System
	{
	private:
		Messenger _messenger;
		Timer _timer;
		Microsecond _update_interval;
	
	protected:
		virtual Message *_retrieve_message(void) { return _messenger.retrieve(); }
		virtual void _dispatch_message(Message *message) { _messenger.dispatch(message); }
		virtual void _calibrate_timer(void) { _timer.set_time_out(2 * _update_interval - _timer.elapsed_time()); }
		virtual bool _should_update(void) const { return _timer.time_out(); }
		
		// Functions handling specific messages. Pass them on by default.
		virtual void _handle_keyboard_message(Message *message) { _dispatch_message(message); }
		virtual void _handle_mouse_message(Message *message) { _dispatch_message(message); }
		virtual void _handle_message(void);
		
	public:
		System(Microsecond update_interval = SYSTEM_DEFAULT_UPDATE_INTERVAL)
				: _update_interval(update_interval), _timer(update_interval) { _timer.reset(); }
		virtual ~System(void) {}
		virtual void update(void) = 0;
		virtual void set_update_interval(Microsecond interval) { _update_interval = interval; }
	};
}

#endif  // WATERY_SYSTEM_H
