//
// Created by Mike Smith on 2017/5/8.
//

#include "world.h"

namespace watery
{
	World *World::_instance = new World;
	
	World::~World(void)
	{
		for (auto &object : _objects)
		{
			delete object.second;
		}
	}
}
