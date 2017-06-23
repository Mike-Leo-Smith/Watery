/// @file rotation.h
/// @brief Header file for class Rotation.
/// @author ZSK
/// @date May 26, 2017

#ifndef WATERY_ROTATION_H
#define WATERY_ROTATION_H

#include "component.h"
#include "../../Framework/Mathematics/quaternion.h"

namespace watery
{
	/// @brief Rotation component for objects.
	/// @see Component
	/// @see Object
	class Rotation : public Component
	{
	private:
		/// @brief Rotation axis.
		/// @see Vector
		Vector _axis;
		
		/// @brief Rotation angle in degrees.
		float _angle;
	
	public:
		/// @brief Construct from the demanded rotation axis and angle.
		/// @param axis Demanded axis.
		/// @param angle Demmanded angle.
		/// @see Vector
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		Rotation(const Vector &axis, float angle = 0)
				: Component("rotation"), _axis(axis), _angle(angle) {}
		
		/// @brief Destructor.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual ~Rotation(void) override {}
		
		/// @brief Get quaternion representing the desired rotation.
		/// @return Quaternion representing the desired rotation.
		/// @see Quaternion
		virtual const Quaternion quaternion(void) const { return Quaternion(_axis, _angle); }
		
		/// @brief Get rotation axis.
		/// @return Rotation axis.
		/// @see Vector
		virtual const Vector &axis(void) const { return _axis; }
		
		/// @brief Get rotation angle.
		/// @return Rotation angle.
		virtual const float angle(void) const { return _angle; }
		
		/// @brief Set rotation axis.
		/// @param axis Demanded rotation axis.
		virtual void set_axis(const Vector &axis) { _axis = axis; }
		
		/// @brief Set rotation anngle.
		/// @param angle Demanded rotation angle.
		virtual void set_angle(float angle) { _angle = angle; }
		
		/// @brief Rotate by delta.
		/// @param delta Difference of rotation angle to apply in degrees.
		virtual void rotate(float delta) { _angle += delta; }
	};
}

#endif  // WATERY_ROTATION_H
