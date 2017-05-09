//
// Created by Mike Smith on 2017/5/9.
//

#ifndef WATERY_MOUSE_MESSAGE_H
#define WATERY_MOUSE_MESSAGE_H

#include "message.h"

namespace watery
{
	class MouseMessage : public Message
	{
	public:
		MouseMessage(Microsecond time_out = KEYBOARD_DEFAULT_TIME_OUT)
				: Message(MESSAGE_MOUSE_EVENT, time_out) {}
	};
}

#endif  // WATERY_MOUSE_MESSAGE_H
