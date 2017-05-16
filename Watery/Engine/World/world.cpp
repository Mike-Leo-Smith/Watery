//
// Created by Mike Smith on 2017/5/8.
//

#include "world.h"

namespace watery
{
	World &World::instance(void)
	{
		static World world;
		return world;
	}
	
	void World::destroy_all(void)
	{
		for (auto &item : _objects)
		{
			delete item.second;
		}
		
		_objects.clear();
		_camera.set_position(Vector());
	}
	
	Object *World::create_object(const std::string &name)
	{
		Object *object = nullptr;
		
		if (!_objects.count(name))
		{
			object = new Object;
			_objects.emplace(name, object);
		}
		
		return object;
	}
	
	World::~World(void)
	{
		destroy_all();
	}
}
