//
// Created by Mike Smith on 2017/4/17.
//

#include <cmath>
#include "graphics.h"
#include "../../Engine/Timer/timer.h"

namespace watery
{
	void Graphics::draw(GLShader &shader, GLVertexArray &vao, float x1, float y1, float x2, float y2, const float *proj, const float *mat)
	{
		static Timer timer;
		
		shader.activate();
		shader.set_uniform_float("x1", x1);
		shader.set_uniform_float("y1", y1);
		shader.set_uniform_float("x2", x2);
		shader.set_uniform_float("y2", y2);
		shader.set_uniform_mat4fv("proj", proj);
		shader.set_uniform_mat4fv("mat", mat);
		
		float red = (float)(1.0 + sin(timer.elapsed_time() / 1500000.0)) / 2.0f;
		float green = (float)(1.0 + sin(timer.elapsed_time() / 1000000.0)) / 2.0f;
		float blue = (float)(1.0 + sin(timer.elapsed_time() / 2000000.0)) / 2.0f;
		
		shader.set_uniform_vec3f("rgb", red, green, blue);
		vao.activate();
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}
}