//
// Created by Mike Smith on 2017/4/17.
//

#include "keyboard.h"

namespace watery
{
	bool Keyboard::key_down(KeyCode check_key) const
	{
		if (!_window.bound())
		{
			return false;
		}
		
		bool is_down = false;
		WindowHandler handler = _window.handler();
		
		switch (check_key)
		{
		case KEY_UP:
			is_down = (bool)glfwGetKey(handler, GLFW_KEY_UP);
			break;
		
		case KEY_DOWN:
			is_down = (bool)glfwGetKey(handler, GLFW_KEY_DOWN);
			break;
		
		case KEY_LEFT:
			is_down = (bool)glfwGetKey(handler, GLFW_KEY_LEFT);
			break;
		
		case KEY_RIGHT:
			is_down = (bool)glfwGetKey(handler, GLFW_KEY_RIGHT);
			break;
		
		default:
			break;
		}
		return is_down;
	}
}