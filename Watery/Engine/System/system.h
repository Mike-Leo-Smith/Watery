//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_SYSTEM_H
#define WATERY_SYSTEM_H

#include <string>
#include <deque>
#include "../Message/messenger.h"

namespace watery
{
	constexpr Microsecond SYSTEM_DEFAULT_UPDATE_INTERVAL = 5000;
	constexpr int SYSTEM_TIMER_CALIBRATION_FREQUENCY = 10;
	
	class System
	{
	private:
		Messenger _messenger;
		Timer _timer;
		Microsecond _interval;
		std::string _name;
		bool _paused;
		
		// Records for calibrating the timer.
		std::deque<Microsecond> _recoder;
		
		// Forbidden functions.
		System(const System &) = delete;
		System &operator=(const System &) = delete;
	
	protected:
		// Basic timer functions.
		virtual Microsecond _elapsed_time(void) const { return _timer.elapsed_time(); }
		
		// Basic progresses for message processing.
		virtual void _dispatch_message(Message *message) { message->sign(_name), _messenger.dispatch(message); }
		
		// Functions handling specific messages. Pass them on by default.
		virtual void _handle_keyboard_message(Message *message) { _dispatch_message(message); }
		virtual void _handle_mouse_message(Message *message) { _dispatch_message(message); }
		
		// Updating tasks.
		virtual void _handle_message(void);
		
		// Interface for updating.
		virtual void _updating_tasks(void) { _handle_message(); }
	
	public:
		System(const std::string &name, Microsecond update_interval = SYSTEM_DEFAULT_UPDATE_INTERVAL);
		virtual ~System(void) {}
		virtual void update(void);
		virtual void start(void);
		virtual void pause(void) { _paused = true; }
	};
}

#endif  // WATERY_SYSTEM_H
