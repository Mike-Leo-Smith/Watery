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
		Microsecond _interval;
		bool _paused;
		bool _terminated;
		
		// Forbidden functions.
		System(const System &) = delete;
		System &operator=(const System &) = delete;
	
	protected:
		// Basic progresses for message processing.
		virtual Message *_retrieve_message(void) { return _messenger.retrieve(); }
		virtual void _dispatch_message(Message *message) { _messenger.dispatch(message); }
		
		// Functions handling specific messages. Pass them on by default.
		virtual void _handle_keyboard_message(Message *message) { _dispatch_message(message); }
		virtual void _handle_mouse_message(Message *message) { _dispatch_message(message); }
		
		// Updating tasks.
		virtual void _handle_message(void);
		
		// Interface for updating.
		virtual void _update(void) { _handle_message(); }
		
		// Endless updating loop, used in the thread of the system.
		virtual void _update_loop(void);
	
	public:
		System(Microsecond update_interval = SYSTEM_DEFAULT_UPDATE_INTERVAL);
		virtual ~System(void) { _terminated = true; }
		virtual void start(void);
		virtual void pause(void) { _paused = true; }
	};
}

#endif  // WATERY_SYSTEM_H
