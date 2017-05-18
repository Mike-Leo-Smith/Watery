//
// Created by Mike Smith on 2017/5/9.
//

#include <gl/glew.h>
#include "logic.h"
#include "../Component/position.h"
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
			if (_world.camera().x() + _window.logical_width() >= 4200 - role_v->vx() + 1)
			{
				_world.camera().move_x(role_v->vx());
			}
		}
		
		if (role_pos->x() < _world.camera().x() + 120)
		{
			_world.camera().move_x(role_v->vx());
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
}