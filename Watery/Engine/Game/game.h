//
// Created by Mike Smith on 2017/5/13.
//

#ifndef WATERY_GAME_H
#define WATERY_GAME_H

#include <map>
#include "../System/system.h"

namespace watery
{
	class Game : public System
	{
	private:
		Window &_window;
		std::map<std::string, System *> _systems;
	
	public:
		Game(void) : _window(Window::instance()), System("game") {}
		virtual ~Game(void) {}
		virtual void add_system(System *system) { _systems.emplace(system->name(), system); }
		virtual void run(void);
	};
}

#endif  // WATERY_GAME_H
