#include <thread>
#include <cmath>
#include <gl/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Watery/Framework/Window/window.h"
#include "Watery/Engine/Timer/timer.h"
#include "Watery/Engine/System/system.h"
#include "Watery/Engine/Message/keyboard_message.h"
#include "Watery/Engine/Input/input.h"
#include "Watery/Framework/Graphics/graphics.h"
#include "Watery/Engine/Camera/camera.h"

class TestSystem : public watery::System
{
private:
	float _counter;

protected:
	virtual void _handle_keyboard_message(watery::Message *message) override
	{
		watery::KeyboardMessage *cast_message = static_cast<watery::KeyboardMessage *>(message);
		
		if (cast_message != nullptr)
		{
			switch (cast_message->code())
			{
			case watery::KEY_UP:
				std::cout << "KEY_UP" << std::endl;
				break;
			case watery::KEY_DOWN:
				std::cout << "KEY_DOWN" << std::endl;
				break;
			case watery::KEY_LEFT:
				std::cout << "KEY_LEFT" << std::endl;
				break;
			case watery::KEY_RIGHT:
				std::cout << "KEY_RIGHT" << std::endl;
				break;
			default:
				break;
			}
		}
	}

public:
	TestSystem(void) : _counter(0), System(50000) {}
};

int main(void)
{
	watery::Window &window = watery::Window::instance();
	window.setup("Test", 800, 600);
	
	watery::Graphics graphics;
	watery::GLShader shader;
	
	std::ifstream vertex_shader("Shaders/rectangle.vert");
	std::ifstream fragment_shader("Shaders/rectangle.frag");
	
	std::stringstream vert_src, frag_src;
	vert_src << vertex_shader.rdbuf();
	frag_src << fragment_shader.rdbuf();
	
	std::string vert = vert_src.str();
	std::string frag = frag_src.str();
	
	shader.compile(vert.c_str(), frag.c_str());
	
	float rect[] =
			{
					0, 0, 0,
					1, 0, 0,
					1, 1, 0,
					0, 1, 0
			};
	
	float proj[] =
			{
					1.25e-3f, 0, 0, 0,
					0, 1.67e-3f, 0, 0,
					0, 0, 1.0f, 0,
					0, 0, 0, 1.0f
			};
	
	watery::GLVertexArray vao(rect, 12);
	vao.set_pointers(0, 3, 3, 0);
	
	watery::Camera camera;
	
	glClearColor(0.0, 0.0, 0.0, 1.0);
	while (window.alive())
	{
		camera.move_x(1);
		camera.move_y(1);
		rect[0] += 0.1;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		graphics.draw(shader, vao, -200, -200, 200, 200, proj, camera.mat());
		window.update();
	}
}

