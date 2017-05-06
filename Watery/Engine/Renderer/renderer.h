//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_RENDERER_H
#define WATERY_RENDERER_H

#include "../../Framework/Window/window.h"
#include "../System/system.h"

namespace watery
{
	class Renderer
	{
	private:
		Window &_window;
	
	public:
		Renderer(void) : _window(Window::instance()) {}
	};
}

#endif  // WATERY_RENDERER_H
