//
// Created by Mike Smith on 2017/6/5.
//

#include "mouse.h"

namespace watery
{
	const Vector Mouse::get_position(void) const
	{
		double x = 0;
		double y = 0;
		GLFWwindow *handler = _window.handler();
		
		glfwGetCursorPos(handler, &x, &y);
		
		return Vector((float)x, (float)y);
	}
	
	bool Mouse::left_down(void) const
	{
		return (bool)glfwGetMouseButton(_window.handler(), GLFW_MOUSE_BUTTON_LEFT);
	}
	
	bool Mouse::right_down(void) const
	{
		return (bool)glfwGetMouseButton(_window.handler(), GLFW_MOUSE_BUTTON_RIGHT);
	}
}
