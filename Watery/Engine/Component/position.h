//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_POSITION_H
#define WATERY_POSITION_H

#include "component.h"
#include "../../Data/Vector/vector.h"

namespace watery
{
	class Position : public Component
	{
	private:
		Vector _position;
	
	public:
		Position(const Vector &position = Vector()) : Component(COMPONENT_POSITION), _position(position) {}
		virtual ~Position(void) {}
		virtual const Vector &position(void) const { return _position; }
		virtual void set_position(const Vector &position) { _position = position; }
		virtual void move(const Vector &direction) { _position += direction; }
		virtual void move_x(float dx) { _position.set_x(_position.x() + dx); }
		virtual void move_y(float dy) { _position.set_y(_position.y() + dy); }
		virtual void move_z(float dz) { _position.set_z(_position.z() + dz); }
		virtual float x(void) const { return _position.x(); }
		virtual float y(void) const { return _position.y(); }
		virtual float z(void) const { return _position.z(); }
	};
}

#endif  // WATERY_POSITION_H
