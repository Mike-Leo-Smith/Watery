//
// Created by Mike Smith on 2017/5/11.
//

#ifndef WATERY_KEYBOARD_H
#define WATERY_KEYBOARD_H

#include "../Window/window.h"

#define GLFW_KEY_CODE(key_code) GLFW_##key_code

namespace watery
{
	typedef uint_fast64_t KeyboardStatus;
	
	enum KeyCode
	{
		KEY_UP = 1 << 0,
		KEY_DOWN = 1 << 1,
		KEY_LEFT = 1 << 2,
		KEY_RIGHT = 1 << 3,
		KEY_SPACE = 1 << 4,
		KEY_EQUAL = 1 << 5,
		KEY_MINUS = 1 << 6,
	};
	
	class Keyboard
	{
	private:
		Window &_window;
	
	public:
		Keyboard(void) : _window(Window::instance()) {}
		KeyboardStatus status(void) const;
	};
}

#endif  // WATERY_KEYBOARD_H
