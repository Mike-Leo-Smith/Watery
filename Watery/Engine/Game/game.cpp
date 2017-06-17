//
// Created by Mike Smith on 2017/5/13.
//

#ifdef _WIN32
#include <gl/glew.h>
#include <glfw/glfw3.h>
#endif
#include <thread>
#include "game.h"

namespace watery
{
	void Game::run(void)
	{
		_loader.load_level("1");
		
		for (auto &item : _systems)
		{
			System *system = item.second;
			system->start();
		}
		
		while (_window.alive())
		{
			for (auto &item : _systems)
			{
				System *system = item.second;
				system->update();
			}
#ifdef _WIN32
			glfwWaitEventsTimeout(0.002);
#else
			std::this_thread::sleep_for(std::chrono::microseconds(500));
#endif
		}
	}
}