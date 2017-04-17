//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_POSITION_H
#define WATERY_POSITION_H

#include "component.h"
#include "coord.h"

namespace watery
{
	class Position : public Component
	{
	private:
		Coord _position;
	
	public:
		Position(const Coord &position = Coord()) : Component(COMPONENT_POSITION), _position(position) {}
		virtual ~Position(void) {}
		virtual Coord &position(void) { return _position; }
		virtual const Coord &position(void) const { return _position; }
		virtual void set_position(const Coord &position) { _position = position; }
	};
}

#endif  // WATERY_POSITION_H
