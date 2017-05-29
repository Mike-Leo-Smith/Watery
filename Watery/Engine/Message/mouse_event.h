//
// Created by Mike Smith on 2017/5/9.
//

#ifndef WATERY_MOUSE_EVENT_H
#define WATERY_MOUSE_EVENT_H

#include "message.h"

namespace watery
{
	class MouseEvent : public Message
	{
	public:
		MouseEvent(Microsecond time_out = KEYBOARD_EVENT_DEFAULT_TIME_OUT)
				: Message("mouse_event", time_out) {}
		virtual ~MouseEvent(void) override {}
	};
}

#endif  // WATERY_MOUSE_EVENT_H
