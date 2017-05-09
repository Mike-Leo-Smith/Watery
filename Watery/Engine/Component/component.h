//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_COMPONENT_H
#define WATERY_COMPONENT_H

namespace watery
{
	enum ComponentType
	{
		COMPONENT_UNDEFINED,
		COMPONENT_POSITION,
		COMPONENT_VELOCITY,
		COMPONENT_SHADER,
		COMPONENT_TEXTURE,
		COMPONENT_VERTEX_ARRAY,
		COMPONENT_AUDIO,
		
		COMPONENT_TYPE_COUNT    // This item has to be placed at last.
	};
	
	class Component
	{
	private:
		ComponentType _type;
	
	public:
		Component(ComponentType type = COMPONENT_UNDEFINED) : _type(type) {}
		virtual ~Component(void) {}
		virtual ComponentType type(void) const { return _type; }
	};
}

#endif  // WATERY_COMPONENT_H
