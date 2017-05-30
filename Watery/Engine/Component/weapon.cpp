//
// Created by 97344 on 2017/5/27.
//

#include <sstream>
#include <cmath>
#include <iostream>
#include <algorithm>
#include "weapon.h"
#include "rotation.h"
#include "../Mathematics/mathematics.h"
#define BULLET_SPEED 1000
#define BULLET_OFFSET 0.15
namespace watery
{
	int Weapon::_bullet_count = 0;
	
	void Weapon::fire(Object *owner)
	{
		if (_timer.time_out())
		{
			_timer.reset();
			if (_weapon_type == "normal")
			{
				std::string name = owner->name();
				std::reverse(name.begin(), name.end());
				Object *object = _world.create_object(name + "_bullet" + std::to_string(_bullet_count++), owner->type());
				std::cout << object->name() << std::endl;
				float angle = static_cast<Rotation *>(owner->component("rotation"))->angle();
				if(owner->type()=="enemy")angle+=180;
				Vector v = Mathematics::cartesian(BULLET_SPEED, angle);
				object->create_component("velocity", std::to_string(v.x()) + " " + std::to_string(v.y()) + " 0");
				
				Vector pos = static_cast<Position *>(owner->component("position"))->vector() + Vector(v.x(), v.y()) * BULLET_OFFSET;
				std::stringstream buffer;
				std::string pos_str;
				
				buffer << pos.x() << ' ' << pos.y() << ' ' << pos.z();
				pos_str = buffer.str();
				
				object->create_component("position", pos_str);
				object->create_component("shader", "sprite_shader");
				
				object->create_component("texture", "face_image");
				GLTexture *gl_texture = static_cast<Texture *>(owner->component("texture"))->texture();
				static_cast<Texture *>(object->component("texture"))->bind_texture(gl_texture);
				
				if(owner->name()=="enemy3")
				{
					object->create_component("texture","xuming_image");
				}
				
				object->create_component("vertex_array", "small_bullet_va");
				object->create_component("bounding_shape", "small_bullet_shape");
				object->create_component("lifetime", "3000000");
				//object->create_component("animation", "");
			}
			else if (_weapon_type == "shotgun")
			{
				for (int angle = -60; angle <= 60; angle += 60)
				{
					std::string name = owner->name();
					std::reverse(name.begin(), name.end());
					Object *object = _world.create_object(name + "_bullet" + std::to_string(_bullet_count++),"enemy");
					
					if(owner->type()=="enemy")angle+=180;
					Vector v = Mathematics::cartesian(BULLET_SPEED, angle);
					if(owner->type()=="enemy")angle-=180;
					object->create_component("velocity", std::to_string(v.x()) + " " + std::to_string(v.y()) + " 0");
					
					Vector pos = static_cast<Position *>(owner->component("position"))->vector() + Vector(v.x(), v.y()) * BULLET_OFFSET;
					std::stringstream buffer;
					std::string pos_str;
					
					buffer << pos.x() << ' ' << pos.y() << ' ' << pos.z();
					pos_str = buffer.str();
					
					object->create_component("position", pos_str);
					object->create_component("shader", "sprite_shader");
					
					object->create_component("texture", "face_image");
					GLTexture *gl_texture = static_cast<Texture *>(owner->component("texture"))->texture();
					static_cast<Texture *>(object->component("texture"))->bind_texture(gl_texture);
					
					object->create_component("vertex_array", "small_bullet_va");
					object->create_component("bounding_shape", "small_bullet_shape");
					object->create_component("lifetime", "3000000");
				}
			}else if(_weapon_type=="shotgun2")
			{
				for (int angle = -180; angle < 180; angle += 30)
				{
					std::string name = owner->name();
					std::reverse(name.begin(), name.end());
					Object *object = _world.create_object(name + "_bullet" + std::to_string(_bullet_count++),"enemy");
					
					if(owner->type()=="enemy")angle+=180;
					Vector v = Mathematics::cartesian(BULLET_SPEED, angle);
					if(owner->type()=="enemy")angle-=180;
					object->create_component("velocity", std::to_string(v.x()) + " " + std::to_string(v.y()) + " 0");
					
					Vector pos = static_cast<Position *>(owner->component("position"))->vector() + Vector(v.x(), v.y()) * BULLET_OFFSET;
					std::stringstream buffer;
					std::string pos_str;
					
					buffer << pos.x() << ' ' << pos.y() << ' ' << pos.z();
					pos_str = buffer.str();
					
					object->create_component("position", pos_str);
					object->create_component("shader", "sprite_shader");
					
					object->create_component("texture", "face_image");
					GLTexture *gl_texture = static_cast<Texture *>(owner->component("texture"))->texture();
					static_cast<Texture *>(object->component("texture"))->bind_texture(gl_texture);
					
					object->create_component("vertex_array", "small_bullet_va");
					object->create_component("bounding_shape", "small_bullet_shape");
					object->create_component("lifetime", "3000000");
				}
				if(_life.time_out())
				{
					set_type("shotgun",0);
					owner->create_component("texture","face_image");
					owner->create_component("vertex_array","face_rect");
				}
			}
			else if(_weapon_type=="helix")
			{
				std::string name = owner->name();
				std::reverse(name.begin(), name.end());
				Object *object = _world.create_object(name + "_bullet" + std::to_string(_bullet_count++), owner->type());
				std::cout << object->name() << std::endl;
				float angle = static_cast<Rotation *>(owner->component("rotation"))->angle();
				if(owner->type()=="enemy")angle+=180;
				Vector v = Mathematics::cartesian(BULLET_SPEED, angle);
				object->create_component("velocity", std::to_string(v.x()) + " " + std::to_string(v.y()) + " 0");
				
				Vector pos = static_cast<Position *>(owner->component("position"))->vector() + Vector(v.x(), v.y()) * BULLET_OFFSET;
				std::stringstream buffer;
				std::string pos_str;
				
				buffer << pos.x() << ' ' << pos.y() << ' ' << pos.z();
				pos_str = buffer.str();
				
				object->create_component("position", pos_str);
				object->create_component("shader", "sprite_shader");
				
				object->create_component("texture", "face_image");
				GLTexture *gl_texture = static_cast<Texture *>(owner->component("texture"))->texture();
				static_cast<Texture *>(object->component("texture"))->bind_texture(gl_texture);
				
				if(owner->name()=="enemy3")
				{
					object->create_component("texture","xuming_image");
				}
				
				object->create_component("vertex_array", "small_bullet_va");
				object->create_component("bounding_shape", "small_bullet_shape");
				object->create_component("lifetime", "3000000");
				object->create_component("animation", "helix_animation");
			}
		}
	}
}