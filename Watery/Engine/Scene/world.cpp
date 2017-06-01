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
		_objects.clear();
	}
	
	std::shared_ptr<Object> World::create_object(const std::string &name, const std::string &type)
	{
		if (_objects.count(name))
		{
			_objects.erase(name);
		}
		
		std::shared_ptr<Object> object(new Object(name, type));
		_objects.emplace(name, object);
		
		return object;
	}
	
	World::~World(void)
	{
		destroy_all();
	}
	
	void World::destroy_object(const std::string &name)
	{
		_objects.erase(name);
	}
}
