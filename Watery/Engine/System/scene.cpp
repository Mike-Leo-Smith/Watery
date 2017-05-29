//
// Created by Mike Smith on 2017/5/25.
//

#include "scene.h"
#include "../Physics/shape.h"
#include "../Component/bounding_shape.h"
#include "../Physics/physics.h"
#include "../Component/animation.h"
#include "../Component/lifetime.h"
#include "../Component/angular_velocity.h"
#include "../Component/rotation.h"
#include "../Component/constraint.h"
#include "../Component/weapon.h"

void watery::Scene::do_updating_tasks(void)
{
	handle_message();
	detect_collisions();
	advance_status();
}

void watery::Scene::detect_collisions(void)
{
	auto iter_begin = _world.objects().begin();
	auto iter_end = _world.objects().end();
	
	for (auto i = _world.objects().begin(); i != _world.objects().end(); i++)
	{
		Object *object = i->second;
		
		if (object->enabled("bounding_shape"))
		{
			// Detect collisions with brute force.
			for (auto j = i; j != _world.objects().end(); j++)
			{
				if (i == j) { continue; }
				
				Object *another = j->second;
				
				if (another->enabled("bounding_shape"))
				{
					Shape *s1 = static_cast<BoundingShape *>(object->component("bounding_shape"))->shape();
					Shape *s2 = static_cast<BoundingShape *>(another->component("bounding_shape"))->shape();
					Vector p1 = static_cast<Position *>(object->component("position"))->vector();
					Vector p2 = static_cast<Position *>(another->component("position"))->vector();
					
					if (Physics::collision(*s1, p1, *s2, p2))
					{
						dispatch_message(new CollisionEvent(object, another));
					}
				}
			}
		}
	}
}

void watery::Scene::advance_status(void)
{
	for (auto &object_item : _world.objects())
	{
		Object *object = object_item.second;
		
		// Updating health.
		if (object->enabled("health"))
		{
			if (static_cast<Health *>(object->component("health"))->dying())
			{
				dispatch_message(new DyingEvent(object));
			}
		}
		
		// Update position by velocity.
		if (object->enabled("velocity") && object->enabled("position"))
		{
			Vector velocity = static_cast<Velocity *>(object->component("velocity"))->vector();
			static_cast<Position *>(object->component("position"))->move(velocity * delta_time() * 1e-6f);
		}
		
		// Update rotation by angular velocity.
		if (object->enabled("angular_velocity") && object->enabled("rotation"))
		{
			float angular_velocity = static_cast<AngularVelocity *>(object->component("angular_velocity"))->omega();
			static_cast<Rotation *>(object->component("rotation"))->rotate(angular_velocity * delta_time() * 1e-6f);
		}
		
		// Weapon.
		if (object->enabled("weapon"))
		{
			Weapon *weapon = static_cast<Weapon *>(object->component("weapon"));
			
			if (weapon->is_auto())
			{
				weapon->fire(object);
			}
		}
		
		// Animate.
		if (object->enabled("animation"))
		{
			static_cast<Animation *>(object->component("animation"))->animate(object);
		}
		
		// Constrain.
		if (object->enabled("constraint"))
		{
			static_cast<Constraint *>(object->component("constraint"))->constrain(object);
		}
		
		// Removing dead objects (typically used with particles). Make sure it is placed at the last.
		if (object->enabled("lifetime"))
		{
			if (static_cast<Lifetime *>(object->component("lifetime"))->dead())
			{
				_world.destroy_object(object->name());
			}
		}
	}
}
