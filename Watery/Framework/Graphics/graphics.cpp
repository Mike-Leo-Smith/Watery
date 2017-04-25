//
// Created by Mike Smith on 2017/4/17.
//

#include <cmath>
#include <set>
#include <map>
#include "graphics.h"
#include "../../Engine/Timer/timer.h"
#include "gl_texture.h"

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
	
	void Graphics::draw_sprite(GLShader &shader, const float *projection, const float *view, float x, float y, const unsigned char *data, int width, int height, int depth)
	{
		static float vertices[] =
				{
						0, 0,
						1, 0,
						1, 1,
						0, 1
				};
		static GLVertexArray vao(vertices, 8);
		static std::map<const unsigned char *, GLTexture *> textures;
		GLTexture *texture;
		
		vao.set_pointers(0, 2, 2, 0);
		
		if (textures.count(data))
		{
			texture = textures.at(data);
		}
		else
		{
			texture = new GLTexture(data, width, height, depth);
			textures.emplace(data, texture);
		}
		
		texture->activate(0);
		shader.activate();
		shader.set_uniform_int("sampler", 0);
		shader.set_uniform_vec2f("size", width, height);
		shader.set_uniform_mat4fv("projection", projection);
		shader.set_uniform_mat4fv("view", view);
		vao.activate();
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}
}