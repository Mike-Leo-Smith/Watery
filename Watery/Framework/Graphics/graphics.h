//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_GRAPHICS_H
#define WATERY_GRAPHICS_H

#include "gl_shader.h"
#include "../Window/window.h"
#include "gl_vertex_array.h"

namespace watery
{
	class Graphics
	{
	private:
		Window &_window;
	
	public:
		Graphics(void) : _window(Window::instance()) {}
	};
}

#endif  // WATERY_GRAPHICS_H
