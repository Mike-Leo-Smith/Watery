//
// Created by Mike Smith on 2017/5/5.
//

#ifndef WATERY_WORLD_H
#define WATERY_WORLD_H

#include <map>
#include "../System/system.h"
#include "entity.h"

namespace watery
{
	class World
	{
	private:
		std::map<std::string, Entity *> _world;
	
	public:
	
	};
}

#endif  // WATERY_WORLD_H
