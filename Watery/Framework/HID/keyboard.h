//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_KEYBOARD_H
#define WATERY_KEYBOARD_H

#include "../Context/context.h"

namespace watery
{
	enum KeyCode
	{
		KEY_UNDEFINED,
		
		KEY_UP,
		KEY_DOWN,
		KEY_LEFT,
		KEY_RIGHT,
		
		KEY_CODE_COUNT
	};
	
	class Keyboard
	{
	private:
		Context &_window;
		
	public:
		Keyboard(void) : _window(Context::instance()) {}
		virtual ~Keyboard(void) {}
		virtual bool key_down(KeyCode check_key) const;
	};
}

#endif  // WATERY_KEYBOARD_H
