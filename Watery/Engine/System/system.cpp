//
// Created by Mike Smith on 2017/4/17.
//

#include <thread>
#include <iostream>
#include "system.h"

namespace watery
{
	void System::handle_message(void)
	{
		std::vector<Message *> &messages = _messenger.retrieve();
		
		for (Message *message : messages)
		{
			if (message == nullptr)
			{
				continue;
			}
			
			if (message->time_out())
			{
				delete message;   // Delete expiring messages.
				continue;
			}
			
			if (message->signed_by(_name))
			{
				dispatch_message(message);
				continue;
			}
			
			switch (message->type())
			{
			case MESSAGE_KEYBOARD_EVENT:
				handle_keyboard_message(static_cast<KeyboardMessage *>(message));
				break;
			
			case MESSAGE_MOUSE_EVENT:
				handle_mouse_message(static_cast<MouseMessage *>(message));
				break;
			
			default:
				delete message;     // Delete useless messages.
				break;
			}
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
			updating_tasks();                                              // Do updating tasks.
			
			if (_recoder.size() >= SYSTEM_TIMER_CALIBRATION_FREQUENCY)
			{
				_recoder.pop_front();
			}
			_recoder.push_back(_timer.elapsed_time());
			
			Microsecond accumulated = 0;
			
			for (Microsecond time : _recoder)
			{
				accumulated += time;
			}
			
			Microsecond average = accumulated / _recoder.size();
			Microsecond calibrated = 2 * _interval - average;
			
			std::cout << _name << ": " << 1000000.0 / average << " fps" << std::endl;
			
			if (calibrated <= 0)
			{
				calibrated = _interval;
			}
			
			_timer.set_time_out(calibrated);                                // Calibrate the timer.
			_timer.reset();                                                 // Restart the timer.
		}
	}
	
	System::System(const std::string &name, Microsecond update_interval)
			: _interval(update_interval), _timer(update_interval), _paused(true), _name(name) {}
}