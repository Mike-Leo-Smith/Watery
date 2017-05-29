//
// Created by Mike Smith on 2017/5/9.
//

#ifndef WATERY_SOUND_H
#define WATERY_SOUND_H

#include <gl/glew.h>
#include "system.h"
#include "../Scene/world.h"

namespace watery
{
	class Sound : public System
	{
	private:
		const World &_world;
	
	protected:
		virtual void do_updating_tasks(void) override;
	
	public:
		Sound(const std::string &name = "sound", Microsecond interval = SOUND_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval), _world(World::instance()) {}
		virtual ~Sound(void) {}
	};
}

#endif  // WATERY_SOUND_H
