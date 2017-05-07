#include <vector>
#include <iostream>
#include "Watery/Engine/Resource/resource_manager.h"
#include "Watery/Engine/Component/audio.h"
#include "Watery/Engine/Component/component_factory.h"
#include "Watery/Engine/Mathematics/mathematics.h"

int main(void)
{
	watery::ResourceManager manager;
	watery::ComponentFactory &factory = watery::ComponentFactory::instance();
	
	const watery::ALAudio *al_audio_1 = manager.create_audio("Audio 1", "Assets/Sounds/test.wav");
	watery::Audio *audio_1 = factory.create_audio(al_audio_1);
	delete al_audio_1;
	audio_1->audio()->play(true);
	
	float x = 1.0 / 0;
	std::cout << x << std::endl;
	
	std::cout << sizeof(watery::Mathematics) << std::endl;
	
	for (;;) {}
}
