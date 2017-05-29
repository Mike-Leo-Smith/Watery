//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_RESOURCE_MANAGER_H
#define WATERY_RESOURCE_MANAGER_H

#include <map>
#include <string>
#include "resource_wrapper.h"

namespace watery
{
	class ResourceManager
	{
	private:
		std::map<std::string, ResourceWrapper *> _resources;
		
		ResourceManager(void) {}
		ResourceManager(const ResourceManager &) = delete;
		ResourceManager(ResourceManager &&) = delete;
		ResourceManager &operator=(const ResourceManager &) = delete;
		~ResourceManager(void);
	
	public:
		static ResourceManager &instance(void);
		ResourceWrapper *get_resource(const std::string &type, const std::string &name, const std::string &file_name = "");
		void destroy_resource(const std::string &name);
		void destroy_all(void);
	};
}

#endif  // WATERY_RESOURCE_MANAGER_H
