//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_SYSTEM_H
#define WATERY_SYSTEM_H

#include <gl/glew.h>
#include <string>
#include <deque>
#include "../Message/messenger.h"
#include "../Message/keyboard_event.h"
#include "../Message/mouse_event.h"
#include "../Message/collision_event.h"
#include "../Message/dying_event.h"

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
		
		// Delta time from last frame.
		virtual Microsecond delta_time(void) const;
		
		// Functions handling specific messages. Pass them on by default.
		virtual void handle_keyboard_event(KeyboardEvent *message) { dispatch_message(message); }
		virtual void handle_mouse_event(MouseEvent *message) { dispatch_message(message); }
		virtual void handle_collision_event(CollisionEvent *message) { dispatch_message(message); }
		virtual void handle_dying_event(DyingEvent *message) { dispatch_message(message); }
		
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
		virtual const std::string &name(void) const { return _name; }
	};
}

#endif  // WATERY_SYSTEM_H
