//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_COMPONENT_H
#define WATERY_COMPONENT_H

#include <string>

namespace watery
{
	class Component
	{
	private:
		std::string _type;
		bool _enabled;
	
	public:
		Component(const std::string &type = "undefined") : _type(type), _enabled(true) {}
		virtual ~Component(void) {}
		virtual const std::string &type(void) const { return _type; }
		virtual void disable(void) { _enabled = false; }
		virtual void enable(void) { _enabled = true; }
		virtual bool enabled(void) const { return _enabled; }
	};
}

#endif  // WATERY_COMPONENT_H
