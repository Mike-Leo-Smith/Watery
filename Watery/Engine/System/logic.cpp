//
// Created by Mike Smith on 2017/5/9.
//

#include <gl/glew.h>
#include <iostream>
#include "logic.h"
#include "../Component/angular_velocity.h"

namespace watery
{
	void Logic::handle_keyboard_message(KeyboardEvent *message)
	{
		Object *role = _world.object("role");
		Velocity *role_v = static_cast<Velocity *>(role->component("velocity"));
		Position *role_pos = static_cast<Position *>(role->component("position"));
		
		Object *camera = _world.object("camera");
		Position *camera_pos = static_cast<Position *>(camera->component("position"));
		Velocity *camera_v = static_cast<Velocity *>(camera->component("velocity"));
		
		if (message->key_down(KEY_SPACE))
		{
			if (_world.object("background")->enabled("audio"))
			{
				_world.object("background")->disable("audio");
			}
			else
			{
				_world.object("background")->enable("audio");
			}
		}
		
		if (role_v->vy() > -30 && role_v->vy() < 30)
		{
			role_v->set_vy(0);
		}
		
		constexpr float border = 400;
		
		if (role_pos->x() <= 100)
		{
			if (role_v->vx() < 0)
			{
				role_v->set_vx(-0.8f * role_v->vx());
				role_v->set_vy(0.95f * role_v->vy());
			}
			role_pos->set_x(100);
		}
		else if (role_pos->x() >= 4100)
		{
			if (role_v->vx() > 0)
			{
				role_v->set_vx(-0.8f * role_v->vx());
				role_v->set_vy(0.95f * role_v->vy());
			}
			role_pos->set_x(4100);
		}
		
		if (role_pos->y() <= 100)
		{
			if (role_v->vy() < 0)
			{
				role_v->set_vx(0.95f * role_v->vx());
				role_v->set_vy(-0.8f * role_v->vy());
			}
			role_pos->set_y(100);
		}
		else if (role_pos->y() >= _window.logical_height() - 100)
		{
			if (role_v->vy() > 0)
			{
				role_v->set_vx(0.95f * role_v->vx());
				role_v->set_vy(-0.8f * role_v->vy());
			}
			role_pos->set_y(_window.logical_height() - 100);
		}
		
		role_v->accelerate_y(-40.0f);
		
		if (role_pos->x() - camera_pos->x() >= _window.logical_width() - border)
		{
			if (camera_pos->x() + _window.logical_width() < 4200)
			{
				if (role_v->vx() > 0)
				{
					camera_v->set_vx(role_v->vx());
				}
			}
			else
			{
				camera_v->set_vx(0);
				camera_pos->set_x(4200 - _window.logical_width());
			}
		}
		else if (role_pos->x() <= camera_pos->x() + border)
		{
			if (camera_pos->x() > 0)
			{
				if (role_v->vx() < 0)
				{
					camera_v->set_vx(role_v->vx());
				}
			}
			else
			{
				camera_v->set_vx(0);
				camera_pos->set_x(0);
			}
		}
		
		if (message->key_down(KEY_UP))
		{
			role_v->accelerate_y(80.0f);
		}
		
		if (message->key_down(KEY_DOWN))
		{
			role_v->accelerate_y(-10.0f);
		}
		
		if (message->key_down(KEY_LEFT))
		{
			role_v->accelerate_x(-10.0f);
		}
		
		if (message->key_down(KEY_RIGHT))
		{
			role_v->accelerate_x(10.0f);
		}
		
		dispatch_message(message);
		static_cast<AngularVelocity *>(role->component("angular_velocity"))->set_omega(-role_v->vx());
		
		std::cout << "role position " << role_pos->x() << " " << role_pos->y() << std::endl;
		std::cout << "role velocity " << role_v->vx() << " " << role_v->vy() << std::endl;
		std::cout << "camera position " << camera_pos->x() << " " << camera_pos->y() << std::endl;
		std::cout << "camera velocity " << camera_v->vx() << " " << camera_v->vy() << std::endl << std::endl;
	}
}