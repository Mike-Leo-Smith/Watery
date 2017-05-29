//
// Created by Mike Smith on 2017/5/8.
//

#ifndef WATERY_GL_GRAPHICS_H
#define WATERY_GL_GRAPHICS_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "gl_shader.h"
#include "gl_vertex_array.h"
#include "gl_texture.h"
#include "../Window/window.h"

namespace watery
{
	class GLGraphics
	{
	private:
		Window &_window;
	
	public:
		GLGraphics(void) : _window(Window::instance()) {}
		void clear(float red = 0, float green = 0, float blue = 0, float alpha = 0.0);
		void draw(const GLVertexArray *vertex_array);
		void poll_events(void);
		void swap_buffers(void);
	};
}

#endif  // WATERY_GL_GRAPHICS_H
