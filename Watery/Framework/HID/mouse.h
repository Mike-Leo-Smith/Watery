//
// Created by Mike Smith on 2017/6/5.
//

#ifndef WATERY_MOUSE_H
#define WATERY_MOUSE_H

#include "../Window/window.h"
#include "../Mathematics/vector.h"

namespace watery
{
	class Mouse
	{
	private:
		Window &_window;
	
	public:
		Mouse(void) : _window(Window::instance()) {}
		const Vector get_position(void) const;
		bool left_down(void) const;
		bool right_down(void) const;
	};
}

#endif  // WATERY_MOUSE_H
