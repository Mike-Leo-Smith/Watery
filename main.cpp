#include <thread>
#include <cmath>
#include <gl/glew.h>
#include <iostream>
#include "Watery/Framework/Window/window.h"
#include "Watery/Engine/Timer/timer.h"
#include "Watery/Engine/System/system.h"
#include "Watery/Engine/Message/keyboard_message.h"
#include "Watery/Engine/Input/input.h"

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
	window.setup("Hello", 800, 600);
	
	watery::Input input(50000);
	input.start();
	
	TestSystem system;
	system.start();
	
	watery::Timer timer;
	
	while (window.alive())
	{
		input.update();
		system.update();
		
		float brightness = (float)(1.0 + sin(timer.elapsed_time() / 1500000.0)) / 2.0f;
		
		glClearColor(brightness, brightness, brightness, brightness);
		glClear(GL_COLOR_BUFFER_BIT);
		window.update();
	}
}

