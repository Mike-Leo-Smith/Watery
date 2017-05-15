//
// Created by Mike Smith on 2017/5/13.
//

#ifndef WATERY_GAME_H
#define WATERY_GAME_H

#include <map>
#include "../System/system.h"

namespace watery
{
	class Game
	{
	private:
		Window &_window;
		std::map<std::string, System *> _systems;
	
	public:
		Game(void) : _window(Window::instance()) {}
		virtual ~Game(void) {}
		virtual void add_system(const std::string &name, System *system) { _systems.emplace(name, system); }
		virtual void remove_system(const std::string &name) { _systems.erase(name); }
		virtual void run(void);
	};
}

#endif  // WATERY_GAME_H
