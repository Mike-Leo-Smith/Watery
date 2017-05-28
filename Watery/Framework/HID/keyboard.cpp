//
// Created by Mike Smith on 2017/5/11.
//

#include "keyboard.h"

namespace watery
{
	KeyboardStatus Keyboard::status(void) const
	{
		KeyboardStatus keyboard_status = 0;
		GLFWwindow *window = _window.handler();
		
		if (window != nullptr)
		{
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_UP)) ? KEY_UP : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_DOWN)) ? KEY_DOWN : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_LEFT)) ? KEY_LEFT : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_RIGHT)) ? KEY_RIGHT : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_SPACE)) ? KEY_SPACE : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_EQUAL)) ? KEY_EQUAL : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_MINUS)) ? KEY_MINUS : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_J)) ? KEY_J : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_A)) ? KEY_A : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_S)) ? KEY_S : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_D)) ? KEY_D : 0;
			keyboard_status |= glfwGetKey(window, GLFW_KEY_CODE(KEY_W)) ? KEY_W : 0;
		}
		
		return keyboard_status;
	}
}