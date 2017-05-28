//
// Created by Mike Smith on 2017/5/26.
//

#include "object.h"

namespace watery
{
	void Object::create_component(const std::string &type, const std::string &arg)
	{
		Component *component = _factory.create_component(type, arg);
		
		if (component != nullptr)
		{
			if (_components.count(type))
			{
				_factory.destroy_component(_components.at(type));
				_components.erase(type);
			}
			_components.emplace(type, component);
		}
	}
	
	void Object::destroy_component(const std::string &type)
	{
		if (_components.count(type))
		{
			_factory.destroy_component(_components.at(type));
			_components.erase(type);
		}
	}
	
	void Object::destroy_all_components(void)
	{
		for (auto &object_item : _components)
		{
			_factory.destroy_component(object_item.second);
		}
		_components.clear();
	}
}