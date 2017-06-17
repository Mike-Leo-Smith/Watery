/// @file angular_velocity.h
/// @brief Header file for class AngularVelocity.
/// @author Mike Smith
/// @date May 26, 2017

#ifndef WATERY_ANGULAR_VELOCITY_H
#define WATERY_ANGULAR_VELOCITY_H

#include "component.h"

namespace watery
{
	/// @brief Angular velocity component for objects.
	/// @see Component
	class AngularVelocity : public Component
	{
	private:
		/// @brief Value of the angular velocity.
		float _omega;
	
	public:
		/// @brief Default constructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see ComponentFactory
		/// @see Component
		/// @see Object
		/// @param omega Value of the angular velocity.
		AngularVelocity(float omega) : Component("angular_velocity"), _omega(omega) {}
		
		/// @brief Destructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see ComponentFactory
		/// @see Object
		virtual ~AngularVelocity(void) {}
		
		/// @brief Get the value of the angular velocity.
		/// @return Value of the angular velocity.
		virtual float omega(void) const { return _omega; }
		
		/// @brief Set the value of the angular velocity.
		/// @param omega New value of the angular velocity.
		virtual void set_omega(float omega) { _omega = omega; }
		
		/// @brief Change the value of angular velocity by delta.
		/// @param delta Difference to apply.
		virtual void accelarate(float delta) { _omega += delta; }
	};
}

#endif  // WATERY_ANGULAR_VELOCITY_H
