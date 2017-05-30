//
// Created by Mike Smith on 2017/4/17.
//

#include <gl/glew.h>
#include <iostream>

#include "system.h"
#include "render.h"
#include "../Mathematics/mathematics.h"
#include "../Component/rotation.h"

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
	
	const Matrix Render::get_view_matrix(void) const
	{
		Matrix view;
		Object *camera = _world.object("camera");
		
		if (camera != nullptr)
		{
			if (camera->enabled("position"))
			{
				Position *camera_pos = static_cast<Position *>(camera->component("position"));
				view *= Mathematics::translation(-camera_pos->vector());
			}
			
			if (camera->enabled("rotation"))
			{
				Rotation *camera_rot = static_cast<Rotation *>(camera->component("rotation"));
				view *= Mathematics::rotation(camera_rot->axis(), -camera_rot->angle());
			}
		}
		
		return view;
	}
	
	void Render::render_scene(void)
	{
		Matrix view = get_view_matrix();
		Matrix proj = get_proj_matrix();
		
		_graphics.poll_events();
		_graphics.clear(0.3, 0.4, 0.6);
		
		for (auto &item : _world.objects())
		{
			Matrix model;
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
				
				shader->set_uniform_float("pixel_size_x", static_cast<Velocity *>(_world.object("camera")->component("velocity"))->vx() * 5e-7f);
				
				if (object->enabled("position"))
				{
					Vector position = static_cast<Position *>(object->component("position"))->vector();
					model *= Mathematics::translation(position);
				}
				
				if (object->enabled("rotation"))
				{
					Quaternion rotation = static_cast<Rotation *>(object->component("rotation"))->quaternion();
					model *= Mathematics::rotation(rotation);
				}
				
				shader->set_uniform_mat4fv("model", model.entries());
				
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
