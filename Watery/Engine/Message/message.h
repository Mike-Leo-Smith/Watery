//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_MESSAGE_H
#define WATERY_MESSAGE_H

#include <ctime>
#include "../Timer/timer.h"
#include "../../Framework/Clock/clock.h"

namespace watery
{
	constexpr Microsecond MESSAGE_DEFAULT_TIME_OUT = 50000;
	
	enum MessageType
	{
		MESSAGE_UNDEFINED,
		
		MESSAGE_KEYBOARD_EVENT,
		MESSAGE_MOUSE_EVENT,
		MESSAGE_SCENE_EVENT,
		
		MESSAGE_TYPE_COUNT
	};
	
	class Message
	{
	private:
		MessageType _type;
		Timer _timer;
		
	public:
		Message(MessageType type = MESSAGE_UNDEFINED, Microsecond time_out = MESSAGE_DEFAULT_TIME_OUT)
				: _type(type), _timer(time_out) { _timer.reset(); }
		virtual ~Message(void) {}
		virtual MessageType type(void) const { return _type; }
		virtual bool time_out(void) const { return _timer.time_out(); }
	};
}

#endif  // WATERY_MESSAGE_H
