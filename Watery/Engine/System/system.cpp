//
// Created by Mike Smith on 2017/4/17.
//

#include <thread>
#include "system.h"

namespace watery
{
	void System::_handle_message(void)
	{
		Message *message = _retrieve_message();
		
		if (message == nullptr)
		{
			return;
		}
		
		if (message->time_out())
		{
			delete message;   // Delete expiring messages.
			return;
		}
		
		if (message->signed_by(_name))
		{
			_dispatch_message(message);
			return;
		}
		
		switch (message->type())
		{
		case MESSAGE_KEYBOARD_EVENT:
			_handle_keyboard_message(message);
			break;
		
		case MESSAGE_MOUSE_EVENT:
			_handle_mouse_message(message);
			break;
		
		default:
			delete message;     // Delete useless messages.
			break;
		}
	}
	
	void System::start(void)
	{
		if (_paused)
		{
			_paused = false;
			_timer.set_time_out(_interval);
			_timer.reset();
		}
	}
	
	void System::update(void)
	{
		if (!_paused && _timer.time_out())
		{
			_updating_tasks();                                              // Do updating tasks.
			_timer.set_time_out(2 * _interval - _timer.elapsed_time());     // Calibrate the timer.
			_timer.reset();                                                 // Restart the timer.
		}
	}
	
	System::System(const std::string &name, Microsecond update_interval)
			: _interval(update_interval), _timer(update_interval), _paused(true), _name(name) {}
}