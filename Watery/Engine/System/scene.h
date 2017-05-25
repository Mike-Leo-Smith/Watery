//
// Created by Mike Smith on 2017/5/25.
//

#ifndef WATERY_SCENE_H
#define WATERY_SCENE_H

#include "system.h"
#include "../Scene/world.h"

namespace watery
{
	// The scene system does object updating tasks not so logical.
	class Scene : public System
	{
	private:
		World &_world;
		
		virtual void detect_collisions(void);
		virtual void advance_status(void);
	
	protected:
		virtual void do_updating_tasks(void) override;
	
	public:
		Scene(const std::string &name = "scene", Microsecond update_interval = SCENE_DEFAULT_UPDATA_INTERVAL)
				: System(name, update_interval), _world(World::instance()) {}
		virtual ~Scene(void) override {}
	};
}

#endif  // WATERY_SCENE_H
