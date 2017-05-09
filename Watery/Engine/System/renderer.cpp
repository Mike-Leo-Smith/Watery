//
// Created by Mike Smith on 2017/4/17.
//

#include <gl/glew.h>
#include <iostream>
#include "system.h"
#include "renderer.h"
#include "../Mathematics/mathematics.h"
#include "../Component/vertex_array.h"
#include "../Component/shader.h"
#include "../Component/position.h"
#include "../Component/texture.h"

namespace watery
{
	void Renderer::updating_tasks(void)
	{
		handle_message();
		
		Mathematics math;
		Matrix model;
		Matrix view = math.camera_at(_world.camera().position());
		Matrix proj = get_proj_matrix();
		
		_graphics.clear(0.3, 0.4, 0.6);
		
		for (const auto &item : _world.objects())
		{
			const Object *object = item.second;
			
			const GLShader *shader = nullptr;
			const GLVertexArray *vertex_array = nullptr;
			const GLTexture *texture = nullptr;
			
			if (object->enabled(COMPONENT_SHADER))
			{
				shader = static_cast<const Shader *>(object->component(COMPONENT_SHADER))->shader();
				shader->activate();
				
				shader->set_uniform_mat4fv("proj", proj.entries());
				shader->set_uniform_mat4fv("view", view.entries());
				
				if (object->enabled(COMPONENT_POSITION))
				{
					model = math.translation(static_cast<const Position *>(object->component(COMPONENT_POSITION))->position());
					shader->set_uniform_mat4fv("model", model.entries());
				}
				
				if (object->enabled(COMPONENT_TEXTURE))
				{
					texture = static_cast<const Texture *>(object->component(COMPONENT_TEXTURE))->texture();
					texture->activate(0);
					shader->set_uniform_int("sampler", 0);
				}
				
				if (object->enabled(COMPONENT_VERTEX_ARRAY))
				{
					vertex_array = static_cast<const VertexArray *>(object->component(COMPONENT_VERTEX_ARRAY))->vertex_array();
					_graphics.draw(vertex_array);
				}
			}
		}
		_graphics.swap_buffers();
	}
	
	const Matrix Renderer::get_proj_matrix(void) const
	{
		Mathematics math;
		
		Matrix trans = math.translation(Vector(-1, -1));
		Matrix scale = math.scale(Vector(2.0f / _window.width(), 2.0f / _window.height(), 1.0f));
		return trans * scale;
	}
	
	void Renderer::init(const std::string &window_name, int width, int height)
	{
		_window.setup(window_name.c_str(), width, height);
	}
}