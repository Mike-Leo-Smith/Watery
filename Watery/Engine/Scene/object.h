//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_OBJECT_H
#define WATERY_OBJECT_H

#include <map>
#include "../Component/component.h"
#include "../Component/component_factory.h"

namespace watery
{
	class Object
	{
	private:
		std::string _name;
		std::string _type;
		ComponentFactory &_factory;
		
	protected:
		std::map<std::string, Component *> _components;
	
	public:
		Object(const std::string &name, const std::string &type)
				: _name(name), _type(type), _factory(ComponentFactory::instance()) {}
		virtual ~Object(void) { destroy_all_components(); }
		virtual const std::string &name(void) const { return _name; }
		virtual const std::string &type(void) const { return _type; }
		virtual bool bound(const std::string &type) const { return (_components.count(type) != 0); }
		virtual bool enabled(const std::string &type) const { return (_components.count(type) && _components.at(type)->enabled()); }
		virtual Component *component(const std::string &type) { return _components.count(type) ? _components.at(type) : nullptr; }
		virtual const Component *component(const std::string &type) const { return _components.count(type) ? _components.at(type) : nullptr; }
		virtual void create_component(const std::string &type, const std::string &arg);
		virtual void destroy_component(const std::string &type);
		virtual void destroy_all_components(void);
		virtual void enable(const std::string &type) { if (_components.count(type) != 0) _components.at(type)->enable(); }
		virtual void disable(const std::string &type) { if (_components.count(type) != 0) _components.at(type)->disable(); }
	};
}

#endif  // WATERY_OBJECT_H