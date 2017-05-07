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
		template<typename COMPONENT_TYPE> COMPONENT_TYPE *decode(void) { return static_cast<COMPONENT_TYPE *>(this); }
		template<typename COMPONENT_TYPE> const COMPONENT_TYPE *decode(void) const { return static_cast<const COMPONENT_TYPE *>(this); }
	};
}

#endif  // WATERY_COMPONENT_H
