//
// Created by Mike Smith on 2017/5/9.
//

#ifndef WATERY_LOGIC_H
#define WATERY_LOGIC_H

#include "system.h"
#include "../World/world.h"
#include "../Message/keyboard_message.h"
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
		virtual void handle_keyboard_message(KeyboardMessage *message) override;
	
	public:
		Logic(const std::string &name = "Logic", Microsecond interval = LOGIC_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval), _world(World::instance()), _window(Window::instance()), _manager(ResourceManager::instance()) {}
		virtual ~Logic(void) {}
		virtual void init(void);
	};
}

#endif  // WATERY_LOGIC_H
