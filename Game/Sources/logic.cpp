//
// Created by Mike Smith on 2017/5/26.
//

#include <iostream>
#include "logic.h"
#include "../../Watery/Engine/Component/angular_velocity.h"
#include "../../Watery/Engine/Physics/circle.h"
#include "../../Watery/Engine/Component/bounding_shape.h"
#include "../../Watery/Engine/Physics/physics.h"
#include "../../Watery/Engine/Mathematics/mathematics.h"

void Logic::handle_keyboard_event(watery::KeyboardEvent *message)
{
	watery::Object *role = _world.object("role");
	watery::Velocity *role_v = static_cast<watery::Velocity *>(role->component("velocity"));
	watery::Position *role_pos = static_cast<watery::Position *>(role->component("position"));
	
	watery::Object *camera = _world.object("camera");
	watery::Position *camera_pos = static_cast<watery::Position *>(camera->component("position"));
	watery::Velocity *camera_v = static_cast<watery::Velocity *>(camera->component("velocity"));
	
	if (message->key_down(watery::KEY_SPACE))
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
	
	if (role_pos->x() <= 200)
	{
		if (role_v->vx() < 0)
		{
			role_v->set_vx(-0.8f * role_v->vx());
			role_v->set_vy(0.95f * role_v->vy());
		}
		role_pos->set_x(200);
	}
	else if (role_pos->x() >= 4000)
	{
		if (role_v->vx() > 0)
		{
			role_v->set_vx(-0.8f * role_v->vx());
			role_v->set_vy(0.95f * role_v->vy());
		}
		role_pos->set_x(4000);
	}
	
	if (role_pos->y() <= 200)
	{
		if (role_v->vy() < 0)
		{
			role_v->set_vx(0.95f * role_v->vx());
			role_v->set_vy(-0.8f * role_v->vy());
		}
		role_pos->set_y(200);
	}
	else if (role_pos->y() >= _window.logical_height() - 200)
	{
		if (role_v->vy() > 0)
		{
			role_v->set_vx(0.95f * role_v->vx());
			role_v->set_vy(-0.8f * role_v->vy());
		}
		role_pos->set_y(_window.logical_height() - 200);
	}
	
	role_v->accelerate_y(-40.0f);
	
	if (message->key_down(watery::KEY_UP))
	{
		role_v->accelerate_y(80.0f);
	}
	
	if (message->key_down(watery::KEY_DOWN))
	{
		role_v->accelerate_y(-10.0f);
	}
	
	if (message->key_down(watery::KEY_LEFT))
	{
		role_v->accelerate_x(-10.0f);
	}
	
	if (message->key_down(watery::KEY_RIGHT))
	{
		role_v->accelerate_x(10.0f);
	}
	
	dispatch_message(message);
	static_cast<watery::AngularVelocity *>(role->component("angular_velocity"))->set_omega(-watery::Mathematics::degrees(role_v->vx() / 200));
}

void Logic::handle_collision_event(watery::CollisionEvent *message)
{
	watery::Object *role = nullptr;
	watery::Object *collider = nullptr;
	
	if (message->object1()->name() == "role")
	{
		role = message->object1();
		collider = message->object2();
	}
	else //if (message->object2()->name() == "role")
	{
		role = message->object2();
		collider = message->object1();
	}
	
	if (role != nullptr)
	{
		watery::Circle *role_shape = static_cast<watery::Circle *>(static_cast<watery::BoundingShape *>(role->component("bounding_shape"))->shape());
		watery::Circle *coll_shape = static_cast<watery::Circle *>(static_cast<watery::BoundingShape *>(collider->component("bounding_shape"))->shape());
		watery::Position *role_pos = static_cast<watery::Position *>(role->component("position"));
		watery::Position *coll_pos = static_cast<watery::Position *>(collider->component("position"));
		watery::Velocity *role_v = static_cast<watery::Velocity *>(role->component("velocity"));
		watery::Velocity *coll_v = static_cast<watery::Velocity *>(collider->component("velocity"));
		watery::Vector norm = (role_shape->center() + role_pos->vector()) - (coll_shape->center() + coll_pos->vector());
		
		norm.normalize();
		
		float role_vp = norm * role_v->vector();
		float coll_vp = norm * coll_v->vector();
		
		//if (role_vp < 0)
		{
			watery::Vector role_vn = role_vp * norm;
			watery::Vector role_vt = role_v->vector() - role_vn;
			watery::Vector coll_vn = coll_vp * norm;
			watery::Vector coll_vt = coll_v->vector() - coll_vn;
			
			role_v->set(role_vt + coll_vn);
			coll_v->set(coll_vt + role_vn);
			
			role_pos->set(coll_pos->vector() + norm * (role_shape->radius() + coll_shape->radius() + 1));
			
			std::cout << watery::Physics::collision(*role_shape, role_pos->vector(), *coll_shape, coll_pos->vector());
			
			std::cout << "role position " << role_pos->x() << " " << role_pos->y() << std::endl;
			std::cout << "role velocity " << role_v->vx() << " " << role_v->vy() << std::endl;
			std::cout << "camera position " << coll_pos->x() << " " << coll_pos->y() << std::endl;
			std::cout << "coll velocity " << coll_v->vx() << " " << coll_v->vy() << std::endl << std::endl;
		}
	}
	
	delete message;
}

void Logic::handle_dying_event(watery::DyingEvent *message)
{
	delete message;
}

void Logic::update_camera(void)
{
	constexpr float border = 600;
	
	watery::Object *role = _world.object("role");
	watery::Velocity *role_v = static_cast<watery::Velocity *>(role->component("velocity"));
	watery::Position *role_pos = static_cast<watery::Position *>(role->component("position"));
	
	watery::Object *camera = _world.object("camera");
	watery::Position *camera_pos = static_cast<watery::Position *>(camera->component("position"));
	watery::Velocity *camera_v = static_cast<watery::Velocity *>(camera->component("velocity"));
	
	if (role_pos->x() - camera_pos->x() >= _window.logical_width() - border)
	{
		if (camera_pos->x() + _window.logical_width() < 4200)
		{
			camera_v->set_vx(role_v->vx());
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
			camera_v->set_vx(role_v->vx());
		}
		else
		{
			camera_v->set_vx(0);
			camera_pos->set_x(0);
		}
	}
	
	if (camera_pos->x() > 4200 - _window.logical_width())
	{
		camera_pos->set_x(4200 - _window.logical_width());
	}
	
	if (camera_pos->x() < 0)
	{
		camera_pos->set_x(0);
	}
}

void Logic::do_updating_tasks(void)
{
	handle_message();
	update_camera();
}
