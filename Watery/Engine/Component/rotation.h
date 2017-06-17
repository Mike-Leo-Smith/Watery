//
// Created by Mike Smith on 2017/5/26.
//

#ifndef WATERY_ROTATION_H
#define WATERY_ROTATION_H

#include "component.h"
#include "../../Framework/Mathematics/quaternion.h"

namespace watery
{
	class Rotation : public Component
	{
	private:
		Vector _axis;
		float _angle;
	
	public:
		Rotation(const Vector &axis, float angle = 0)
				: Component("rotation"), _axis(axis), _angle(angle) {}
		virtual ~Rotation(void) override {}
		virtual const Quaternion quaternion(void) const { return Quaternion(_axis, _angle); }
		virtual const Vector &axis(void) const { return _axis; }
		virtual const float angle(void) const { return _angle; }
		virtual void set_axis(const Vector &axis) { _axis = axis; }
		virtual void set_angle(float angle) { _angle = angle; }
		virtual void rotate(float delta) { _angle += delta; }
	};
}

#endif  // WATERY_ROTATION_H
