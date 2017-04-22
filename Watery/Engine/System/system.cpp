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
			delete (message);   // Delete expiring messages.
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
	
	void System::_update_loop(void)
	{
		while (!_terminated)
		{
			if (!_paused && _timer.time_out())
			{
				_update();                                                      // Do updating tasks.
				_timer.set_time_out(2 * _interval - _timer.elapsed_time());     // Calibrate the timer.
				_timer.reset();                                                 // Restart the timer.
			}
			
			// Sleep for a little while to lower the CPU occupancy.
			std::this_thread::sleep_for(std::chrono::microseconds(_interval / 128));
		}
	}
	
	System::System(Microsecond update_interval)
			: _interval(update_interval), _timer(update_interval), _paused(true), _terminated(false)
	{
		std::thread thread([&] { this->_update_loop(); });
		thread.detach();
	}
}