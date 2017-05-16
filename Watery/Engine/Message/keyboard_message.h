//
// Created by Mike Smith on 2017/4/18.
//

#ifndef WATERY_KEYBOARD_MESSAGE_H
#define WATERY_KEYBOARD_MESSAGE_H

#include "message.h"
#include "../../Framework/Window/window.h"
#include "../../Framework/HID/keyboard.h"

namespace watery
{
	class KeyboardMessage : public Message
	{
	private:
		KeyboardStatus _keyboard_status;
		
	public:
		KeyboardMessage(KeyboardStatus code = 0, Microsecond time_out = KEYBOARD_DEFAULT_TIME_OUT)
				: _keyboard_status(code), Message(MESSAGE_KEYBOARD_EVENT, time_out) {}
		virtual ~KeyboardMessage(void) {}
		virtual KeyboardStatus keyboard_status(void) const { return _keyboard_status; }
		virtual bool key_down(KeyCode code) const { return (bool)(_keyboard_status & code); }
	};
}

#endif  // WATERY_KEYBOARD_MESSAGE_H
