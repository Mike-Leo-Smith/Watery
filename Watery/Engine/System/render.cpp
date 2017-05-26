//
// Created by Mike Smith on 2017/4/17.
//

#include <gl/glew.h>
#include <iostream>

#include "system.h"
#include "render.h"
#include "../Mathematics/mathematics.h"
#include "../Component/vertex_array.h"
#include "../Component/shader.h"
#include "../Component/position.h"
#include "../Component/texture.h"

namespace watery
{
	void Render::do_updating_tasks(void)
	{
		handle_message();
		render_scene();
	}
	
	const Matrix Render::get_proj_matrix(void) const
	{
		Matrix ortho = Mathematics::ortho_proj(0, _window.logical_width(), 0.0f, _window.logical_height(), -100, 100);
		return ortho;
	}
	
	void Render::render_scene(void)
	{
		Matrix model;
		Matrix view = Mathematics::camera_at(_world.camera().position());
		Matrix proj = get_proj_matrix();
		
		_graphics.poll_events();
		_graphics.clear(0.3, 0.4, 0.6);
		
		for (auto &item : _world.objects())
		{
			Object *object = item.second;
			
			GLShader *shader = nullptr;
			GLVertexArray *vertex_array = nullptr;
			GLTexture *texture = nullptr;
			
			if (object->enabled("shader"))
			{
				shader = static_cast<Shader *>(object->component("shader"))->shader();
				shader->activate();
				
				shader->set_uniform_mat4fv("proj", proj.entries());
				shader->set_uniform_mat4fv("view", view.entries());
				
				if (object->enabled("position"))
				{
					Vector position = static_cast<Position *>(object->component("position"))->position();
					
					model = Mathematics::translation(position);
					shader->set_uniform_mat4fv("model", model.entries());
				}
				
				if (object->enabled("texture"))
				{
					texture = static_cast<Texture *>(object->component("texture"))->texture();
					texture->activate(0);
					shader->set_uniform_int("sampler", 0);
				}
				
				if (object->enabled("vertex_array"))
				{
					vertex_array = static_cast<VertexArray *>(object->component("vertex_array"))->vertex_array();
					_graphics.draw(vertex_array);
				}
			}
		}
		_graphics.swap_buffers();
	}
}
