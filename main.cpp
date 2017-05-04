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
#include "Watery/Engine/Scene/scene.h"
#include "Watery/Framework/Image/lodepng.h"
#include "Watery/Engine/Resource/resource_manager.h"

int main(void)
{
	watery::Window &window = watery::Window::instance();
	window.setup("Test", 800, 600);
	
	watery::Graphics graphics;
	watery::GLShader shader;
	
	std::ifstream vertex_shader("Scripts/Shaders/sprite.vert");
	std::ifstream fragment_shader("Scripts/Shaders/sprite.frag");
	
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
					1.25e-3f * 2, 0, 0, 0,
					0, 1.67e-3f * 2, 0, 0,
					0, 0, 1.0f, 0,
					-1, -1, 0, 1.0f
			};
	
	watery::GLVertexArray vao(rect, 12);
	vao.set_pointers(0, 3, 3, 0);
	
	watery::Camera camera;
	
	watery::Scene scene("Scene", 15000);
	watery::Input input("Input", 50000);
	
	scene.start();
	input.start();
	
	unsigned int width, height;
	std::vector<unsigned char> pixels;
	
	lodepng::decode(pixels, width, height, "Assets/Images/face.png");
	std::cout << width << " " << height << std::endl;
	
	watery::Timer timer(16000);
	
	watery::Resource resource;
	watery::ALAudio *audio = resource.load_audio("Assets/Sounds/test.wav");
	
	audio->play(true);
	
	glClearColor(0.2, 0.3, 0.4, 1.0);
	while (window.alive())
	{
		input.update();
		scene.update();
		
		if (timer.time_out())
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			graphics.draw_sprite(shader, proj, scene.camera().mat(), 0, 0, pixels.data(), width, height, 4);
			window.update();
			timer.reset();
		}
	}
}
