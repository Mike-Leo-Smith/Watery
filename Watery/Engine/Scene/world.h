//
// Created by Mike Smith on 2017/5/8.
//

#ifndef WATERY_WORLD_H
#define WATERY_WORLD_H

#include <memory>
#include <string>
#include <map>
#include <gl/glew.h>
#include "object.h"

namespace watery
{
	// Objects are created and managed by Scene.
	class World
	{
	private:
		std::map<std::string, std::shared_ptr<Object>> _objects;
		
		World(void) {}
		World(const World &) = delete;
		World(World &&) = delete;
		World &operator=(const World &) = delete;
		~World(void);
	
	public:
		static World &instance(void);
		std::shared_ptr<Object> create_object(const std::string &name, const std::string &type = "undefined");
		std::shared_ptr<Object> object(const std::string &name) { return (_objects.count(name) ? _objects.at(name) : nullptr); }
		const std::shared_ptr<Object> object(const std::string &name) const { return (_objects.count(name) ? _objects.at(name) : nullptr); }
		std::map<std::string, std::shared_ptr<Object>> &objects(void) { return _objects; };
		const std::map<std::string, std::shared_ptr<Object>> &objects(void) const { return _objects; };
		void destroy_object(const std::string &name);
		void destroy_all(void);
	};
}

#endif  // WATERY_WORLD_H
