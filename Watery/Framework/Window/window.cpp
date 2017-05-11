//
// Created by Mike Smith on 2017/4/24.
//

#include <gl/glew.h>
#include <glfw/glfw3.h>
#include "window.h"

namespace watery
{
	Window::~Window(void)
	{
		if (_handler != nullptr)
		{
			glfwDestroyWindow(_handler);
		}
	}
	
	void Window::setup(const char *name, float logical_width, float logical_height)
	{
		_logical_height = logical_height;
		
		if (_handler == nullptr)
		{
			glfwInit();
			
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			
			_handler = glfwCreateWindow((int)logical_width, (int)logical_height, name, nullptr, nullptr);
			glfwMakeContextCurrent(_handler);
			
			int frame_width, frame_height;
			glfwGetFramebufferSize(_handler, &frame_width, &frame_height);
			
			glewExperimental = GL_TRUE;
			glewInit();
			
			glViewport(0, 0, frame_width, frame_height);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_MULTISAMPLE);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
	
	int Window::width(void) const
	{
		int width = 0, height = 0;
		
		if (_handler != nullptr)
		{
			glfwGetFramebufferSize(_handler, &width, &height);
		}
		
		return width;
	}
	
	int Window::height(void) const
	{
		int width = 0, height = 0;
		
		if (_handler != nullptr)
		{
			glfwGetFramebufferSize(_handler, &width, &height);
		}
		return height;
	}
	
	Window &Window::instance(void)
	{
		static Window window;
		return window;
	}
	
	float Window::logical_width(void) const
	{
		int width = 0, height = 0;
		
		if (_handler != nullptr)
		{
			glfwGetFramebufferSize(_handler, &width, &height);
		}
		
		return _logical_height / height * width;
	}
}