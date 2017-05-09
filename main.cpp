#include <gl/glew.h>
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

int main(void)
{
	watery::Renderer *renderer = new watery::Renderer;
	watery::Logic *logic = new watery::Logic;
	watery::Input *input = new watery::Input;
	
	renderer->init("Test", 800, 600);
	logic->init();
	
	renderer->start();
	logic->start();
	input->start();
	
	while (!glfwWindowShouldClose(watery::Window::instance().handler()))
	{
		glfwPollEvents();
		
		input->update();
		logic->update();
		renderer->update();
	}
}
