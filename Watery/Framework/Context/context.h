//
// Created by Mike Smith on 2017/4/18.
//

#ifndef WATERY_CONTEXT_H
#define WATERY_CONTEXT_H

#include <GLFW/glfw3.h>

namespace watery
{
	typedef GLFWwindow *WindowHandler;
	
	class Context
	{
	private:
		static Context *_instance;
		WindowHandler _handler;
		
		// Forbidden functions.
		Context(void) : _handler(nullptr) {}
		Context(const Context &context) = delete;
		virtual ~Context(void) {}
		Context &operator=(const Context &context) = delete;
		
	public:
		virtual WindowHandler handler(void) { return _handler; }
		virtual bool bound(void) const { return (_handler != nullptr); }
		virtual void bind(WindowHandler handler) { _handler = handler; }
		virtual void unbind(void) { _handler = nullptr; }
		static Context &instance(void) { return *_instance; }
	};
}

#endif  // WATERY_CONTEXT_H
