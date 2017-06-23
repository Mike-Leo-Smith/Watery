/// @file game.h
/// @brief Header file for class Game.
/// @author ZSK
/// @date May 13, 2017

#ifndef WATERY_GAME_H
#define WATERY_GAME_H

#include <map>
#include "../System/system.h"
#include "../Loader/loader.h"

/// @brief Namespace for the engine.
namespace watery
{
	class Game : public System
	{
	private:
		Window &_window;
		Loader &_loader;
		std::map<std::string, System *> _systems;
	
	public:
		Game(void) : _window(Window::instance()), _loader(Loader::instance()), System("game") {}
		virtual ~Game(void) {}
		virtual void add_system(System *system) { _systems.emplace(system->name(), system); }
		virtual void configure(const std::string &xml_name) { _loader.configure(xml_name); }
		virtual void run(void);
	};
}

#endif  // WATERY_GAME_H
