//
// Created by Mike Smith on 2017/5/5.
//

#include <al/alut.h>
#include "al_initializer.h"

namespace watery
{
	ALInitializer *ALInitializer::_instance = new ALInitializer;
	
	ALInitializer::ALInitializer(void)
	{
		alutInit(nullptr, nullptr);
	}
}
