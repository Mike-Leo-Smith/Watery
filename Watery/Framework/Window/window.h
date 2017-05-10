//
// Created by Mike Smith on 2017/4/24.
//

#ifndef WATERY_WINDOW_H
#define WATERY_WINDOW_H

#include <glfw/glfw3.h>

namespace watery
{
	enum KeyCode
	{
		KEY_UNDEFINED,
		
		KEY_UP,
		KEY_DOWN,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_SPACE,
		KEY_PLUS,
		KEY_MINUS,
		
		KEY_CODE_COUNT
	};
	
	class Window
	{
	private:
		GLFWwindow *_handler;
		float _logical_height;
		
		Window(void) : _handler(nullptr) {}
		Window(const Window &) = delete;
		Window(Window &&) = delete;
		Window &operator=(const Window &) = delete;
		~Window(void);
	
	public:
		GLFWwindow *handler(void) { return _handler; }
		void setup(const char *name, float logical_width, float logical_height);
		void rename(const char *name);
		void resize(int width, int height);
		bool key_down(KeyCode key) const;
		bool alive(void) const { return (_handler != nullptr && !glfwWindowShouldClose(_handler)); }
		void update(void);
		int width(void) const;
		int height(void) const;
		float logical_width(void) const;
		float logical_height(void) const { return _logical_height; }
		float scale(void) const { return height() / _logical_height; }
		static Window &instance(void);
	};
}

#endif  // WATERY_WINDOW_H
