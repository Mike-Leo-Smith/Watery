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
	enum DrawType
	{
		TRIANGLE_FAN = GL_TRIANGLE_FAN,
		TRIANGLE_STRIPE = GL_TRIANGLE_STRIP,
	};
	
	class GLGraphics
	{
	private:
		Window &_window;
	
	public:
		GLGraphics(void) : _window(Window::instance()) {}
		void clear(float red = 0, float green = 0, float blue = 0, float alpha = 1.0);
		void draw(const GLVertexArray *vertex_array, DrawType draw_type = TRIANGLE_FAN);
		void swap_buffers(void);
	};
}

#endif  // WATERY_GL_GRAPHICS_H
