//
// Created by Mike Smith on 2017/5/8.
//

#include "gl_graphics.h"

namespace watery
{
	void GLGraphics::clear(float red, float green, float blue, float alpha)
	{
		glClearColor(red, green, blue, alpha);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	
	void GLGraphics::draw(const GLVertexArray *vertex_array, DrawType draw_type)
	{
		vertex_array->activate();
		glDrawArrays(draw_type, 0, vertex_array->elements());
	}
	
	void GLGraphics::swap_buffers(void)
	{
		glfwSwapBuffers(_window.handler());
	}
}