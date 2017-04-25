//
// Created by Mike Smith on 2017/4/24.
//

#include <gl/glew.h>
#include <glfw/glfw3.h>
#include "window.h"

namespace watery
{
	Window *Window::_instance = new Window;
	
	Window::~Window(void)
	{
		if (_handler != nullptr)
		{
			glfwDestroyWindow(_handler);
		}
	}
	
	bool Window::key_down(KeyCode key) const
	{
		if (_handler == nullptr)
		{
			return false;
		}
		
		bool is_down = false;
		
		switch (key)
		{
		case KEY_UP:
			is_down = (bool)glfwGetKey(_handler, GLFW_KEY_UP);
			break;
		
		case KEY_DOWN:
			is_down = (bool)glfwGetKey(_handler, GLFW_KEY_DOWN);
			break;
		
		case KEY_LEFT:
			is_down = (bool)glfwGetKey(_handler, GLFW_KEY_LEFT);
			break;
		
		case KEY_RIGHT:
			is_down = (bool)glfwGetKey(_handler, GLFW_KEY_RIGHT);
			break;
		
		default:
			break;
		}
		return is_down;
	}
	
	void Window::setup(const char *name, int width, int height)
	{
		if (_handler == nullptr)
		{
			glfwInit();
			
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			
			_handler = glfwCreateWindow(width, height, name, nullptr, nullptr);
			glfwMakeContextCurrent(_handler);
			
			int frame_width, frame_height;
			glfwGetFramebufferSize(_handler, &frame_width, &frame_height);
			
			glewExperimental = GL_TRUE;
			glewInit();
			
			glViewport(0, 0, frame_width, frame_height);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_MULTISAMPLE);
		}
	}
	
	void Window::rename(const char *name)
	{
		if (_handler != nullptr)
		{
			glfwSetWindowTitle(_handler, name);
		}
	}
	
	void Window::resize(int width, int height)
	{
		if (_handler != nullptr)
		{
			int frame_width, frame_height;
			
			glfwSetWindowSize(_handler, width, height);
			glfwGetFramebufferSize(_handler, &frame_width, &frame_height);
			glViewport(0, 0, frame_width, frame_height);
		}
	}
	
	void Window::update(void)
	{
		if (_handler != nullptr)
		{
			glfwSwapBuffers(_handler);
			glfwPollEvents();
		}
	}
}