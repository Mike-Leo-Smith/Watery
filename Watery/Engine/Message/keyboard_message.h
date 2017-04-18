//
// Created by Mike Smith on 2017/4/18.
//

#ifndef WATERY_KEYBOARD_MESSAGE_H
#define WATERY_KEYBOARD_MESSAGE_H

#include "message.h"
#include "../../Framework/HID/keyboard.h"

namespace watery
{
	constexpr Microsecond KEYBOARD_DEFAULT_TIME_OUT = 50000;
	
	class KeyboardMessage : public Message
	{
	private:
		KeyCode _code;
		
	public:
		KeyboardMessage(KeyCode code = KEY_UNDEFINED, Microsecond time_out = KEYBOARD_DEFAULT_TIME_OUT)
				: _code(code), Message(MESSAGE_KEYBOARD_EVENT, time_out) {}
		virtual ~KeyboardMessage(void) {}
		virtual KeyCode code(void) const { return _code; }
	};
}

#endif  // WATERY_KEYBOARD_MESSAGE_H
