//
// Created by Mike Smith on 2017/5/9.
//

#include <gl/glew.h>
#include "logic.h"
#include "../Component/position.h"
#include "../Component/vertex_array.h"
#include "../Component/shader.h"
#include "../Component/texture.h"

namespace watery
{
	void Logic::handle_keyboard_message(KeyboardMessage *message)
	{
		constexpr float delta = 20;
		
		switch (message->code())
		{
		case KEY_UP:
			static_cast<Position *>(_world.object("Role")->component(COMPONENT_POSITION))->move_y(delta);
			break;
		case KEY_DOWN:
			static_cast<Position *>(_world.object("Role")->component(COMPONENT_POSITION))->move_y(-delta);
			break;
		case KEY_LEFT:
			static_cast<Position *>(_world.object("Role")->component(COMPONENT_POSITION))->move_x(-delta);
			break;
		case KEY_RIGHT:
			static_cast<Position *>(_world.object("Role")->component(COMPONENT_POSITION))->move_x(delta);
			break;
		default:
			break;
		}
		
		dispatch_message(message);
	}
	
	void Logic::init(void)
	{
		const GLTexture *gl_texture = _manager.get_texture("texture", "Assets/Images/face.png");
		GLShader *gl_shader = _manager.get_shader("shader", "Scripts/Shaders/sprite.vert", "Scripts/Shaders/sprite.frag");
		GLVertexArray *gl_vertex_array = _manager.get_vertex_array("vertex array", "Assets/VertexArrays/Rectangle.va");
		
		Component *texture = new Texture(gl_texture);
		Component *shader = new Shader(gl_shader);
		Component *vertex_array = new VertexArray(gl_vertex_array);
		Component *position = new Position();
		
		Object *object = new Object;
		
		object->bind_component(texture);
		object->bind_component(shader);
		object->bind_component(vertex_array);
		object->bind_component(position);
		
		_world.add_object("Role", object);
	}
}