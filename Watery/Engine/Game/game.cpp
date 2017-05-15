//
// Created by Mike Smith on 2017/5/13.
//

#include <thread>
#include "game.h"

namespace watery
{
	void Game::run(void)
	{
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
			std::this_thread::sleep_for(std::chrono::microseconds(500));
		}
	}
}