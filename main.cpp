#include <gl/glew.h>
#include <thread>
#include "Watery/Engine/Scene/world.h"
#include "Watery/Engine/System/render.h"
#include "Watery/Engine/Mathematics/mathematics.h"
#include "Watery/Engine/System/logic.h"
#include "Watery/Engine/System/input.h"
#include "Watery/Engine/System/sound.h"
#include "Watery/Engine/Loader/loader.h"
#include "Watery/Engine/System/scene.h"
#include "Watery/Engine/Game/game.h"

int main(void)
{
	watery::Loader &loader = watery::Loader::instance();
	
	loader.configure("Scripts/Levels/demo.xml");
	loader.load_level("1");
	
	watery::Render *render = new watery::Render;
	watery::Logic *logic = new watery::Logic;
	watery::Input *input = new watery::Input;
	watery::Sound *sound = new watery::Sound;
	watery::Scene *scene = new watery::Scene;
	
	watery::Game *game = new watery::Game;
	
	game->add_system(render);
	game->add_system(logic);
	game->add_system(input);
	game->add_system(sound);
	game->add_system(scene);
	
	game->run();
}
