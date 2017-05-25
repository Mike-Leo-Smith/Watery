//
// Created by Mike Smith on 2017/4/18.
//

#ifndef WATERY_KEYBOARD_EVENT_H
#define WATERY_KEYBOARD_EVENT_H

#include "message.h"
#include "../../Framework/Window/window.h"
#include "../../Framework/HID/keyboard.h"

namespace watery
{
	class KeyboardEvent : public Message
	{
	private:
		KeyboardStatus _keyboard_status;
		
	public:
		KeyboardEvent(KeyboardStatus code = 0, Microsecond time_out = KEYBOARD_DEFAULT_TIME_OUT)
				: _keyboard_status(code), Message("keyboard_event", time_out) {}
		virtual ~KeyboardEvent(void) override {}
		virtual KeyboardStatus keyboard_status(void) const { return _keyboard_status; }
		virtual bool key_down(KeyCode code) const { return (bool)(_keyboard_status & code); }
	};
}

#endif  // WATERY_KEYBOARD_EVENT_H
