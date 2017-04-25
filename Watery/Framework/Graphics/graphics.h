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
		void draw(GLShader &shader, GLVertexArray &vao, float x1, float y1, float x2, float y2, const float *proj, const float *mat);
	};
}

#endif  // WATERY_GRAPHICS_H
