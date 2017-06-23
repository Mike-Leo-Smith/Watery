/// @file loader.h
/// @brief Header file for class Loader.
/// @author ZSK
/// @date May 16, 2017

#ifndef WATERY_LOADER_H
#define WATERY_LOADER_H

#include <gl/glew.h>
#include "../System/system.h"
#include "../../Framework/XML/xml_document.h"
#include "../Resource/resource_manager.h"
#include "../Scene/world.h"
#include "../Component/component_factory.h"

namespace watery
{
	class Loader
	{
	private:
		World &_world;
		XMLDocument _config;
		ResourceManager &_manager;
		ComponentFactory &_factory;
		Window &_window;
		
		Loader(void)
				: _manager(ResourceManager::instance()), _world(World::instance()), _factory(ComponentFactory::instance()), _window(Window::instance()) {}
		Loader(const Loader &) = delete;
		Loader(Loader &&) = delete;
		Loader &operator=(const Loader &) = delete;
		~Loader(void) { clear(); }
		
		void clear(void);
	
	public:
		void configure(const std::string &file_name);
		void load_level(const std::string &id);
		static Loader &instance(void);
	};
}

#endif  // WATERY_LOADER_H
