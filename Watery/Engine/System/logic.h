//
// Created by Mike Smith on 2017/5/9.
//

#ifndef WATERY_LOGIC_H
#define WATERY_LOGIC_H

#include "system.h"
#include "../Scene/world.h"
#include "../Message/keyboard_event.h"
#include "../Resource/resource_manager.h"
#include "../Configuration/default.h"

namespace watery
{
	class Logic : public System
	{
	private:
		World &_world;
		Window &_window;
		ResourceManager &_manager;
	
	protected:
		virtual void handle_keyboard_message(KeyboardEvent *message) override;
	
	public:
		Logic(const std::string &name = "logic", Microsecond interval = LOGIC_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval), _world(World::instance()), _window(Window::instance()), _manager(ResourceManager::instance()) {}
		virtual ~Logic(void) {}
	};
}

#endif  // WATERY_LOGIC_H
