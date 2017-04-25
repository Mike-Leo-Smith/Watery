//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_SCENE_H
#define WATERY_SCENE_H

#include <map>
#include <string>
#include "../System/system.h"
#include "../Object/entity.h"
#include "../Camera/camera.h"

namespace watery
{
	class Scene : public System
	{
	private:
		std::map<std::string, Entity *> _world;
		Camera _camera;
	
	public:
		virtual std::map<std::string, Entity *> &world(void) { return _world; }
		virtual Entity *entity(const std::string &name) { return (_world.count(name) ? _world.at(name) : nullptr); }
	};
}

#endif  // WATERY_SCENE_H
