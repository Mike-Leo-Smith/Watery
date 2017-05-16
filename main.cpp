#include <gl/glew.h>
#include <thread>
#include "Watery/Engine/World/world.h"
#include "Watery/Engine/System/renderer.h"
#include "Watery/Engine/Mathematics/mathematics.h"
#include "Watery/Engine/Resource/resource_manager.h"
#include "Watery/Engine/Component/texture.h"
#include "Watery/Engine/Component/position.h"
#include "Watery/Engine/Component/shader.h"
#include "Watery/Engine/Component/vertex_array.h"
#include "Watery/Engine/System/logic.h"
#include "Watery/Engine/System/input.h"
#include "Watery/Engine/System/sound.h"
#include "Watery/Engine/Loader/loader.h"

int main(void)
{
	watery::Loader &loader = watery::Loader::instance();
	
	loader.configure("Scripts/Levels/demo.xml");
	loader.load_level("1");
	
	watery::Renderer *renderer = new watery::Renderer;
	watery::Logic *logic = new watery::Logic;
	watery::Input *input = new watery::Input;
	watery::Sound *sound = new watery::Sound;
	
	// renderer->init("Test", 1600, 1200);
	// logic->init();
	
	renderer->start();
	logic->start();
	input->start();
	sound->start();
	
	while (watery::Window::instance().alive())
	{
		glfwPollEvents();
		
		input->update();
		logic->update();
		renderer->update();
		sound->update();
		
		std::this_thread::sleep_for(std::chrono::microseconds(1000));
	}
}
