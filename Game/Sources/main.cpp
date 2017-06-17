#include "../../Watery/Engine/Scene/world.h"
#include "../../Watery/Engine/System/render.h"
#include "../../Watery/Engine/System/input.h"
#include "../../Watery/Engine/System/sound.h"
#include "../../Watery/Engine/Loader/loader.h"
#include "../../Watery/Engine/System/scene.h"
#include "../../Watery/Engine/Game/game.h"
#include "logic.h"

int main(void)
{
	watery::Game *game = new watery::Game;
	
	game->configure("Scripts/Levels/demo.xml");
	
	watery::Input *input = new watery::Input;
	watery::Sound *sound = new watery::Sound;
	watery::Scene *scene = new watery::Scene;
	watery::Render *render = new watery::Render;
	
	Logic *logic = new Logic;
	
	game->add_system(logic);
	game->add_system(input);
	game->add_system(sound);
	game->add_system(scene);
	game->add_system(render);
	
	game->run();
	
	delete game;
	delete logic;
	delete render;
	delete scene;
	delete sound;
	delete input;
	
	std::vector<int> array;
	std::vector<int>::iterator iter;
	
	return 0;
}
