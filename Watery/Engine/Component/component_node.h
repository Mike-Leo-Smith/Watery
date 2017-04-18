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
		ComponentNode(bool enabled = false, Component *component = nullptr)
				: _enabled(enabled && (component != nullptr)), _component(component) {}
		virtual ~ComponentNode(void) {}
		virtual bool enabled(void) const { return _enabled; }
		virtual bool bound(void) const { return (_component != nullptr); }
		virtual Component *component(void) { return _component; }
		virtual const Component *component(void) const { return _component; }
		virtual void bind(Component *component) { _component = component; }
		virtual void unbind(void) { _component = nullptr; }
		virtual void enable(void) { _enabled = (_component != nullptr); }
		virtual void disable(void) { _enabled = false; }
	};
}

#endif  // WATERY_COMPONENT_NODE_H
