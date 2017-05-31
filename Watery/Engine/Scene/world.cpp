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
	}
	
	Object *World::create_object(const std::string &name, const std::string &type)
	{
		Object *object = nullptr;
		
		if (!_objects.count(name))
		{
			object = new Object(name, type);
			_objects.emplace(name, object);
		}
		
		return object;
	}
	
	World::~World(void)
	{
		destroy_all();
	}
}
