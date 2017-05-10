//
// Created by Mike Smith on 2017/4/17.
//

#include <gl/glew.h>
#include <iostream>

#include <glm/glm.hpp>

#include "system.h"
#include "renderer.h"
#include "../Mathematics/mathematics.h"
#include "../Component/vertex_array.h"
#include "../Component/shader.h"
#include "../Component/position.h"
#include "../Component/texture.h"
#include "../Component/position_animation.h"

namespace watery
{
	void Renderer::do_updating_tasks(void)
	{
		handle_message();
		
		Matrix model;
		Matrix view = Mathematics::camera_at(_world.camera().position());
		Matrix proj = get_proj_matrix();
		
		_graphics.clear(0.3, 0.4, 0.6);
		
		for (auto &item : _world.objects())
		{
			Object *object = item.second;
			
			GLShader *shader = nullptr;
			GLVertexArray *vertex_array = nullptr;
			GLTexture *texture = nullptr;
			
			if (object->enabled(COMPONENT_SHADER))
			{
				shader = static_cast<Shader *>(object->component(COMPONENT_SHADER))->shader();
				shader->activate();
				
				shader->set_uniform_mat4fv("proj", proj.entries());
				shader->set_uniform_mat4fv("view", view.entries());
				
				if (object->enabled(COMPONENT_POSITION))
				{
					Vector position = static_cast<Position *>(object->component(COMPONENT_POSITION))->position();
					
					if (object->enabled(COMPONENT_POSITION_ANIMATION))
					{
						position += static_cast<PositionAnimation *>(object->component(COMPONENT_POSITION_ANIMATION))->offset();
					}
					
					model = Mathematics::translation(position);
					shader->set_uniform_mat4fv("model", model.entries());
				}
				
				if (object->enabled(COMPONENT_TEXTURE))
				{
					texture = static_cast<Texture *>(object->component(COMPONENT_TEXTURE))->texture();
					texture->activate(0);
					shader->set_uniform_int("sampler", 0);
				}
				
				if (object->enabled(COMPONENT_VERTEX_ARRAY))
				{
					vertex_array = static_cast<VertexArray *>(object->component(COMPONENT_VERTEX_ARRAY))->vertex_array();
					_graphics.draw(vertex_array);
				}
			}
		}
		_graphics.swap_buffers();
	}
	
	const Matrix Renderer::get_proj_matrix(void) const
	{
		Matrix ortho = Mathematics::ortho_proj(0, _window.logical_width(), 0.0f, _window.logical_height(), -100, 100);
		return ortho;
	}
	
	void Renderer::init(const std::string &window_name, int width, int height)
	{
		_window.setup(window_name.c_str(), width, height);
	}
}