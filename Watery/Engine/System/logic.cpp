//
// Created by Mike Smith on 2017/5/9.
//

#include <gl/glew.h>
#include "logic.h"
#include "../Component/position.h"
#include "../Component/vertex_array.h"
#include "../Component/shader.h"
#include "../Component/texture.h"
#include "../Component/audio.h"

namespace watery
{
	void Logic::handle_keyboard_message(KeyboardMessage *message)
	{
		constexpr float delta = 20;
		Position *role_pos = static_cast<Position *>(_world.object("Role")->component(COMPONENT_POSITION));
		
		switch (message->code())
		{
		case KEY_UP:
			if (role_pos->y() < _window.height() - 200)
			{
				role_pos->move_y(delta);
			}
			break;
		
		case KEY_DOWN:
			if (role_pos->y() >= delta - 1)
			{
				role_pos->move_y(-delta);
			}
			break;
		
		case KEY_LEFT:
			if (role_pos->x() >= delta - 1)
			{
				role_pos->move_x(-delta);
			}
			break;
		
		case KEY_RIGHT:
			if (role_pos->x() < 4000)
			{
				role_pos->move_x(delta);
			}
			break;
		
		case KEY_PLUS:
			_world.camera().move_z(0.1f);
			break;
		
		case KEY_MINUS:
			_world.camera().move_z(-0.1f);
			break;
		
		case KEY_SPACE:
			if (_world.object("World")->enabled(COMPONENT_AUDIO))
			{
				_world.object("World")->disable(COMPONENT_AUDIO);
			}
			else
			{
				_world.object("World")->enable(COMPONENT_AUDIO);
			}
			
		default:
			break;
		}
		
		if (role_pos->x() > _world.camera().x() + _window.width() - 300)
		{
			if (_world.camera().x() + _window.width() < 4200 - delta + 1)
			{
				_world.camera().move_x(delta);
			}
		}
		
		if (role_pos->x() < _world.camera().x() + 120)
		{
			_world.camera().move_x(-delta);
			if (_world.camera().x() < 0)
			{
				_world.camera().move_x(-_world.camera().x());
			}
		}
		std::cout << _world.camera().z() << std::endl;
		
		dispatch_message(message);
	}
	
	void Logic::init(void)
	{
		GLTexture *gl_texture = _manager.get_texture("texture", "Assets/Images/face.png");
		GLShader *gl_shader = _manager.get_shader("shader", "Scripts/Shaders/sprite.vert", "Scripts/Shaders/sprite.frag");
		GLVertexArray *gl_vertex_array = _manager.get_vertex_array("vertex array", "Assets/VertexArrays/face.va");
		
		Component *texture = new Texture(gl_texture);
		Component *shader = new Shader(gl_shader);
		Component *vertex_array = new VertexArray(gl_vertex_array);
		Component *position = new Position(Vector(0, 0, 4));
		
		Object *object = new Object;
		
		object->bind_component(texture);
		object->bind_component(shader);
		object->bind_component(vertex_array);
		object->bind_component(position);
		
		_world.add_object("Role", object);
		
		GLTexture *bg_gl_texture = _manager.get_texture("background", "Assets/Images/background.png");
		GLVertexArray *bg_gl_va = _manager.get_vertex_array("back vertex array", "Assets/VertexArrays/background.va");
		ALAudio *bg_audio = _manager.get_audio("bg audio", "Assets/Sounds/test.wav");
		
		Component *bg_texture = new Texture(bg_gl_texture);
		Component *bg_va = new VertexArray(bg_gl_va);
		Component *bg_pos = new Position;
		Component *bg_music = new Audio(bg_audio);
		
		Object *background = new Object;
		
		background->bind_component(bg_texture);
		background->bind_component(shader);
		background->bind_component(bg_va);
		background->bind_component(bg_pos);
		background->bind_component(bg_music);
		
		_world.add_object("World", background);
		
		GLShader *gl_sh = _manager.get_shader("standard", "Scripts/Shaders/standard.vert", "Scripts/Shaders/standard.frag");
		GLVertexArray *gl_v = _manager.get_vertex_array("std", "Assets/VertexArrays/pyramid.va");
		
		Component *py_shader = new Shader(gl_sh);
		Component *py_va = new VertexArray(gl_v);
		Component *py_position = new Position(Vector(200, 200, 3));
		
		Object *py = new Object;
		py->bind_component(py_shader);
		py->bind_component(py_va);
		py->bind_component(position);
		
		_world.add_object("ay", py);
	}
}