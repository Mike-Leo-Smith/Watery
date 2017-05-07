//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_OBJECT_H
#define WATERY_OBJECT_H

#include "../Component/component_node.h"
#include "../Component/component_factory.h"

namespace watery
{
	class Object
	{
	protected:
		ComponentNode _components[COMPONENT_TYPE_COUNT];
		ComponentFactory &_factory;
		
	public:
		Object(void) : _factory(ComponentFactory::instance()) {}
		virtual ~Object(void) {}
		virtual bool bound(ComponentType type) const { return _components[type].bound(); }
		virtual bool enabled(ComponentType type) const { return _components[type].enabled(); }
		virtual Component *component(ComponentType type) { return _components[type].component(); }
		virtual const Component *component(ComponentType type) const { return _components[type].component(); }
		virtual void bind_component(Component *component) { _components[component->type()].bind(component); }
		virtual void unbind_component(ComponentType type) { _components[type].unbind(); }
		virtual void enable(ComponentType type) { _components[type].enable(); }
		virtual void disable(ComponentType type) { _components[type].disable(); }
	};
}

#endif  // WATERY_OBJECT_H
