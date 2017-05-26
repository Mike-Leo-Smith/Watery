//
// Created by Mike Smith on 2017/5/25.
//

#include "scene.h"
#include "../Physics/shape.h"
#include "../Component/bounding_shape.h"
#include "../Physics/physics.h"
#include "../Message/collision_event.h"
#include "../Component/animation.h"
#include "../Message/dying_event.h"
#include "../Component/lifetime.h"

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
		
		if (object->enabled("bounding_box"))
		{
			// Detect collisions with brute force.
			for (auto j = i; j != _world.objects().end(); j++)
			{
				if (i == j) { continue; }
				
				Object *another = j->second;
				
				if (another->enabled("bounding_box"))
				{
					Shape *s1 = static_cast<BoundingShape *>(object->component("bounding_shape"))->shape();
					Shape *s2 = static_cast<BoundingShape *>(another->component("bounding_shape"))->shape();
					Vector p1 = static_cast<Position *>(object->component("position"))->position();
					Vector p2 = static_cast<Position *>(another->component("position"))->position();
					
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
		
		// Removing dead objects (typically used with particles).
		if (object->enabled("lifetime"))
		{
			if (static_cast<Lifetime *>(object->component("lifetime"))->dead())
			{
				_world.destroy_object(object->name());
			}
		}
		
		// Update position by velocity.
		if (object->enabled("velocity"))
		{
			Vector position = static_cast<Position *>(object->component("position"))->position();
			Vector velocity = static_cast<Velocity *>(object->component("velocity"))->velocity();
			
			position += velocity * delta_time();
			static_cast<Position *>(object->component("position"))->set_position(position);
		}
		
		// Animate.
		if (object->enabled("animation"))
		{
			static_cast<Animation *>(object->component("animation"))->animate(object);
		}
	}
}
