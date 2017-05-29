//
// Created by Mike Smith on 2017/5/26.
//

#include <iostream>
#include "logic.h"
#include "../../Watery/Engine/Component/angular_velocity.h"
#include "../../Watery/Engine/Physics/circle.h"
#include "../../Watery/Engine/Component/bounding_shape.h"
#include "../../Watery/Engine/Physics/physics.h"
#include "../../Watery/Engine/Component/weapon.h"
#include "../../Watery/Engine/Component/lifetime.h"

constexpr float ACCELERATION = 100.0f;
constexpr float RESISTANCE = 50.f;

void Logic::handle_keyboard_event(watery::KeyboardEvent *message)
{
	watery::Object *role = _world.object("role");
	watery::Velocity *role_v = static_cast<watery::Velocity *>(role->component("velocity"));
	watery::Position *role_pos = static_cast<watery::Position *>(role->component("position"));

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
	
	// Resistance.
	float speed = role_v->vector().length();
	
	if (speed > 30)
	{
		std::cout << speed << std::endl;
		role_v->accelerate(-RESISTANCE / speed * role_v->vector());
	}
	else
	{
		role_v->set(watery::Vector(0, 0, 0));
	}
	
	if (message->key_down(watery::KEY_UP) || message->key_down(watery::KEY_W))
	{
		role_v->accelerate_y(ACCELERATION);
	}
	
	if (message->key_down(watery::KEY_DOWN) || message->key_down(watery::KEY_S))
	{
		role_v->accelerate_y(-ACCELERATION);
	}
	
	if (message->key_down(watery::KEY_LEFT) || message->key_down(watery::KEY_A))
	{
		role_v->accelerate_x(-ACCELERATION);
	}
	
	if (message->key_down(watery::KEY_RIGHT) || message->key_down(watery::KEY_D))
	{
		role_v->accelerate_x(ACCELERATION);
	}
	
	if (message->key_down(watery::KEY_J))
	{
		watery::Weapon *weapon = static_cast<watery::Weapon *>(role->component("weapon"));
		weapon->fire(role);
	}
	
	dispatch_message(message);
//	static_cast<watery::AngularVelocity *>(role->component("angular_velocity"))->set_omega(-role_v->vx());
}

void Logic::handle_collision_event(watery::CollisionEvent *message)
{
	watery::Object *object1=message->object1();
	watery::Object *object2=message->object2();
	
	if((is_type(object1->name(),"role")&&is_type(object2->name(),"elor_bullet"))||
	   (is_type(object1->name(),"elor_bullet")&&is_type(object2->name(),"role")))
	{
		//role and his bullet
	}
	else if((is_type(object1->name(),"enemy")&&is_type(object2->name(),"ymene_bullet"))||
	        (is_type(object1->name(),"ymene_bullet")&&is_type(object2->name(),"emeny")))
	{
		//enemy and its bullet
		std::cout<<"fuck you this man"<<std::endl;
	}
	else if((is_type(object1->name(),"ymene_bullet")&&is_type(object2->name(),"elor_bullet"))||
	        (is_type(object1->name(),"elor_bullet")&&is_type(object2->name(),"ymene_bullet")))
	{
		//bullet
		static_cast<watery::Lifetime *>(object1->component("lifetime"))->set_lifetime(1);
		static_cast<watery::Lifetime *>(object2->component("lifetime"))->set_lifetime(1);
		
	}
	else if((is_type(object1->name(),"ymene_bullet")&&is_type(object2->name(),"role"))||
	        (is_type(object1->name(),"role")&&is_type(object2->name(),"ymene_bullet")))
	{
	
	}
	else if((is_type(object1->name(),"emeny")&&is_type(object2->name(),"elor_bullet"))||
	        (is_type(object1->name(),"elor_bullet")&&is_type(object2->name(),"emeny")))
	{
	
	}
	else if((is_type(object1->name(),"role")&&is_type(object2->name(),"pepper"))||
	        (is_type(object1->name(),"pepper")&&is_type(object2->name(),"role")))
	{
		watery::Object *role= is_type(object1->name(),"pepper")?object2:object1;
		watery::Object *pepper= is_type(object1->name(),"role")?object1:object2;
		static_cast<watery::Lifetime *>(pepper->component("lifetime"))->set_lifetime(1);
		static_cast<watery::Weapon *>(role->component("weapon"))->set_auto(1);
		static_cast<watery::Weapon *>(role->component("weapon"))->set_type("shotgun2");
	}
	/*
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
		}
	}*/
	
	delete message;
}

void Logic::handle_dying_event(watery::DyingEvent *message)
{
	delete message;
}

void Logic::update_camera(void)
{
	constexpr float border = 400;
	
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
