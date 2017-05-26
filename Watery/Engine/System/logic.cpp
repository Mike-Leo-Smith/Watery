//
// Created by Mike Smith on 2017/5/9.
//

#include <gl/glew.h>
#include "logic.h"

namespace watery
{
	void Logic::handle_keyboard_message(KeyboardEvent *message)
	{
		Object *role = _world.object("Role");
		Velocity *role_v = static_cast<Velocity *>(role->component("velocity"));
		Position *role_pos = static_cast<Position *>(role->component("position"));
		
		Object *camera = _world.object("camera");
		Position *camera_position = static_cast<Position *>(camera->component("position"));
		
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
			camera_position->move_z(0.1f);
		}
		
		if (message->key_down(KEY_MINUS))
		{
			camera_position->move_z(-0.1f);
		}
		
		if (message->key_down(KEY_SPACE))
		{
			if (_world.object("Scene")->enabled("audio"))
			{
				_world.object("Scene")->disable("audio");
			}
			else
			{
				_world.object("Scene")->enable("audio");
			}
		}
		
		if (role_pos->x() > camera_position->x() + _window.logical_width() - 300)
		{
			if (camera_position->x() + _window.logical_width() >= 4200 - role_v->vx() + 1)
			{
				camera_position->move_x(role_v->vx());
			}
		}
		
		if (role_pos->x() < camera_position->x() + 120)
		{
			camera_position->move_x(role_v->vx());
			if (camera_position->x() < 0)
			{
				camera_position->move_x(-camera_position->x());
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
		dispatch_message(message);
	}
}