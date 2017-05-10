//
// Created by Mike Smith on 2017/5/7.
//

#include "component_factory.h"

namespace watery
{
	ComponentFactory &ComponentFactory::instance(void)
	{
		static ComponentFactory factory;
		return factory;
	}
}