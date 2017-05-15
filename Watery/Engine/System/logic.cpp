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
#include "../Component/position_animation.h"
#include "../Component/velocity.h"

namespace watery
{
	void Logic::handle_keyboard_message(KeyboardMessage *message)
	{
		Object *role = _world.object("Role");
		Velocity *role_v = static_cast<Velocity *>(role->component(COMPONENT_VELOCITY));
		Position *role_pos = static_cast<Position *>(role->component(COMPONENT_POSITION));
		
		role_pos->move(role_v->velocity());
		
		if (role_pos->y() >= _window.logical_height() - 200)
		{
			role_pos->set_y(_window.logical_height() - 200);
		}
		
		if (role_pos->y() < role_v->vy() - 1)
		{
			role_pos->set_y(role_v->vy() - 1);
		}
		
		if (role_pos->x() < role_v->vx() - 1)
		{
			role_pos->set_x(role_v->vx() - 1);
		}
		
		if (role_pos->x() >= 4000)
		{
			role_pos->set_x(4000);
		}
		
		if (message->key_down(KEY_EQUAL))
		{
			_world.camera().move_z(0.1f);
		}
		
		if (message->key_down(KEY_MINUS))
		{
			_world.camera().move_z(-0.1f);
		}
		
		if (message->key_down(KEY_SPACE))
		{
			if (_world.object("World")->enabled(COMPONENT_AUDIO))
			{
				_world.object("World")->disable(COMPONENT_AUDIO);
			}
			else
			{
				_world.object("World")->enable(COMPONENT_AUDIO);
			}
		}
		
		if (role_pos->x() > _world.camera().x() + _window.logical_width() - 300)
		{
			if (_world.camera().x() + _window.logical_width() < 4200 - role_v->vx() + 1)
			{
				_world.camera().move_x(role_v->vx());
			}
		}
		
		if (role_pos->x() < _world.camera().x() + 120)
		{
			_world.camera().move_x(-role_v->vx());
			if (_world.camera().x() < 0)
			{
				_world.camera().move_x(-_world.camera().x());
			}
		}
		
		if (message->key_down(KEY_UP))
		{
			role_v->accelerate_y(0.1f);
		}
		
		if (message->key_down(KEY_DOWN))
		{
			role_v->accelerate_y(-0.1f);
		}
		
		if (message->key_down(KEY_LEFT))
		{
			role_v->accelerate_x(-0.1f);
		}
		
		if (message->key_down(KEY_RIGHT))
		{
			role_v->accelerate_x(0.1f);
		}
		std::cout << role_v->vx() << " " << role_v->vy() << std::endl;
		std::cout << role_pos->x() << " " << role_pos->y() << std::endl;
		dispatch_message(message);
	}
	
	void Logic::init(void)
	{
		GLTexture *gl_texture = _manager.get_texture("texture", "Assets/Images/face.png");
		GLShader *gl_shader = _manager.get_shader("shader", "Scripts/Shaders/sprite.vert", "Scripts/Shaders/sprite.frag");
		GLVertexArray *gl_vertex_array = _manager.get_vertex_array("vertex array", "Assets/VertexArrays/face.va");
		
		auto trans1 = [](void) -> const Vector
		{
			return Vector(rand() % 30, rand() % 60);
		};
		
		Component *texture = new Texture(gl_texture);
		Component *shader = new Shader(gl_shader);
		Component *vertex_array = new VertexArray(gl_vertex_array);
		Component *position = new Position(Vector(0, 0, 4));
		Component *velocity = new Velocity;
		Component *pos_ani = new PositionAnimation(trans1, 200000);
		
		Object *object = new Object;
		
		object->bind_component(texture);
		object->bind_component(shader);
		object->bind_component(vertex_array);
		object->bind_component(position);
		object->bind_component(velocity);
		object->bind_component(pos_ani);
		
		_world.add_object("Role", object);
		
		GLTexture *bg_gl_texture = _manager.get_texture("background", "Assets/Images/The-Starry-Night.png");
		GLVertexArray *bg_gl_va = _manager.get_vertex_array("back vertex array", "Assets/VertexArrays/background.va");
		ALAudio *bg_audio = _manager.get_audio("bg audio", "Assets/Sounds/test.wav");
		
		auto trans2 = [](void) -> const Vector
		{
			return Vector(-(rand() % 30), -(rand() % 30));
		};
		
		Component *bg_texture = new Texture(bg_gl_texture);
		Component *bg_va = new VertexArray(bg_gl_va);
		Component *bg_pos = new Position;
		Component *bg_music = new Audio(bg_audio);
		Component *pos_ani2 = new PositionAnimation(trans2, 20000);
		
		Object *background = new Object;
		
		background->bind_component(bg_texture);
		background->bind_component(shader);
		background->bind_component(bg_va);
		background->bind_component(bg_pos);
		background->bind_component(bg_music);
		background->bind_component(pos_ani2);
		
		_world.add_object("World", background);
		
		GLShader *gl_sh = _manager.get_shader("standard", "Scripts/Shaders/standard.vert", "Scripts/Shaders/standard.frag");
		GLVertexArray *gl_v = _manager.get_vertex_array("std", "Assets/VertexArrays/pyramid.va");
		
		Component *py_shader = new Shader(gl_sh);
		Component *py_va = new VertexArray(gl_v);
		//Component *py_position = new Position(Vector(200, 200, 3));
		//Component *pos_ani3 = new PositionAnimation;
		
		Object *py = new Object;
		py->bind_component(py_shader);
		py->bind_component(py_va);
		py->bind_component(position);
		//py->bind_component(pos_ani3);
		
		_world.add_object("ay", py);
	}
}