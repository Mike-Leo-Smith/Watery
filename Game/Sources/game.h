//
// Created by Mike Smith on 2017/4/24.
//

#ifndef WATERY_GAME_H
#define WATERY_GAME_H

#include <string>
#include <unordered_map>
#include "../../Watery/Engine/System/system.h"
#include "../../Watery/Framework/Window/window.h"

class Game
{
private:
	std::unordered_map<std::string, watery::System *> _systems;
	watery::Window &_window;
	watery::Messenger _messager;

public:
	Game(void) : _window(watery::Window::instance()) {}
	void init(int width, int height);
	void loop(watery::Microsecond delta_time);
};

#endif  // WATERY_GAME_H
