//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_COMPONENT_NODE_H
#define WATERY_COMPONENT_NODE_H

#include "component.h"

namespace watery
{
	class ComponentNode
	{
	private:
		bool _enabled;
		Component *_component;
	
	public:
		ComponentNode(bool enabled = true, Component *component = nullptr)
				: _enabled(enabled && (component != nullptr)), _component(component) {}
		~ComponentNode(void) {}
		bool enabled(void) const { return _enabled; }
		bool bound(void) const { return (_component != nullptr); }
		Component *component(void) { return _component; }
		const Component *component(void) const { return _component; }
		void bind(Component *component) { _component = component, _enabled = true; }
		void unbind(void) { _component = nullptr; }
		void enable(void) { _enabled = (_component != nullptr); }
		void disable(void) { _enabled = false; }
	};
}

#endif  // WATERY_COMPONENT_NODE_H
