//
// Created by Mike Smith on 2017/4/17.
//

#include <thread>
#include <iostream>
#include "system.h"

namespace watery
{
	System::System(const std::string &name, Microsecond update_interval)
			: _interval(update_interval), _timer(update_interval), _paused(true), _name(name) {}
	
	void System::handle_message(void)
	{
		std::vector<Message *> &messages = _messenger.retrieve();
		
		for (Message *message : messages)
		{
			// Ignore disposed messages.
			if (message->signed_by(_name))
			{
				dispatch_message(message);
				continue;
			}
			
			if (message->type() == "keyboard_event") { handle_keyboard_event(static_cast<KeyboardEvent *>(message)); }
			else if (message->type() == "mouse_event") { handle_mouse_event(static_cast<MouseEvent *>(message)); }
			else if (message->type() == "collision_event") { handle_collision_event(static_cast<CollisionEvent *>(message)); }
			else if (message->type() == "dying_event") { handle_dying_event(static_cast<DyingEvent *>(message)); }
			else { delete message; }
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
			do_updating_tasks();
			calibrate_timer();
		}
	}
	
	void System::calibrate_timer(void)
	{
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
		
		if (calibrated <= 0)
		{
			calibrated = _interval;
		}
		
		_timer.set_time_out(calibrated);
		_timer.reset();
		
		std::cout << _name << ": " << 1000000.0 / average << " fps" << std::endl;
	}
	
	Microsecond System::delta_time(void) const
	{
		return _timer.elapsed_time();
	}
}