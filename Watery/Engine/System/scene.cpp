//
// Created by Mike Smith on 2017/5/25.
//

#include "scene.h"
#include "../Physics/shape.h"
#include "../Component/bounding_shape.h"
#include "../Component/position.h"
#include "../Physics/physics.h"
#include "../Message/collision_event.h"

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
	
	}
}
