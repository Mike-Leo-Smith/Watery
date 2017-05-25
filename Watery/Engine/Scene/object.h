//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_OBJECT_H
#define WATERY_OBJECT_H

#include <map>
#include "../Component/component.h"

namespace watery
{
	class Object
	{
	protected:
		std::map<std::string, Component *> _components;
	
	public:
		Object(void) {}
		virtual ~Object(void) {}
		virtual bool bound(const std::string &type) const { return (_components.count(type) != 0); }
		virtual bool enabled(const std::string &type) const { return (_components.count(type) && _components.at(type)->enabled()); }
		virtual Component *component(const std::string &type) { return _components.count(type) ? _components.at(type) : nullptr; }
		virtual const Component *component(const std::string &type) const { return _components.count(type) ? _components.at(type) : nullptr; }
		virtual void bind_component(Component *component) { _components.emplace(component->type(), component); }
		virtual void unbind_component(const std::string &type) { _components.erase(type); }
		virtual void enable(const std::string &type) { if (_components.count(type) != 0) _components.at(type)->enable(); }
		virtual void disable(const std::string &type) { if (_components.count(type) != 0) _components.at(type)->disable(); }
	};
}

#endif  // WATERY_OBJECT_H
