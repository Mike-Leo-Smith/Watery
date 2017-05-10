//
// Created by Mike Smith on 2017/5/5.
//

#include <al/alut.h>
#include "al_initializer.h"

namespace watery
{
	ALInitializer::ALInitializer(void)
	{
		alutInit(nullptr, nullptr);
	}
	
	ALInitializer &ALInitializer::instance(void)
	{
		static ALInitializer initializer;
		return initializer;
	}
}
