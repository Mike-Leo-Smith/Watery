//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_SYSTEM_H
#define WATERY_SYSTEM_H

#include <string>
#include <deque>
#include "../Message/messenger.h"
#include "../Message/keyboard_message.h"
#include "../Message/mouse_message.h"

namespace watery
{
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
		System(System &&) = delete;
		System &operator=(const System &) = delete;
	
	protected:
		// Basic progresses for message processing.
		virtual void dispatch_message(Message *message) { message->sign(_name), _messenger.dispatch(message); }
		
		// Functions handling specific messages. Pass them on by default.
		virtual void handle_keyboard_message(KeyboardMessage *message) { dispatch_message(message); }
		virtual void handle_mouse_message(MouseMessage *message) { dispatch_message(message); }
		
		// Updating tasks.
		virtual void handle_message(void);
		virtual void calibrate_timer(void);
		
		// Interface for updating.
		virtual void do_updating_tasks(void) { handle_message(); }
	
	public:
		System(const std::string &name, Microsecond update_interval = SYSTEM_DEFAULT_UPDATE_INTERVAL);
		virtual ~System(void) {}
		virtual void update(void);
		virtual void start(void);
		virtual void pause(void) { _paused = true; }
	};
}

#endif  // WATERY_SYSTEM_H
