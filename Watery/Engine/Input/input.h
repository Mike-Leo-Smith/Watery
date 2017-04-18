//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_INPUT_H
#define WATERY_INPUT_H

#include "../System/system.h"
#include "../../Middleware/HID/keyboard.h"

namespace watery
{
	class Input : public System
	{
	private:
		Keyboard _keyboard;
	
	protected:
		virtual void _handle_keyboard_message(Message *message) override;
		virtual void _handle_mouse_message(Message *message) override;
	
	public:
		virtual void update(void) override;
	};
}

#endif  // WATERY_INPUT_H
