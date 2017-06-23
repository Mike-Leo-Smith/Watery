/// @file velocity.h
/// @brief Header file for class Velocity.
/// @author ZSK
/// @date April 19, 2017

#ifndef WATERY_VELOCITY_H
#define WATERY_VELOCITY_H

#include "component.h"

namespace watery
{
	/// @brief Velocity component for objects.
	/// @see Object
	/// @see Component
	class Velocity : public Component
	{
	private:
		/// @brief Velocity vector.
		/// @see Vector
		Vector _velocity;
	
	public:
		/// @brief Construct from a velocity vector.
		/// @param velocity Velocity vector.
		/// @see Vector
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		Velocity(const Vector &velocity = Vector()) : Component("velocity"), _velocity(velocity) {}
		
		/// @brief Destructor.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual ~Velocity(void) override {}
		
		/// @brief Get velocity vector.
		/// @return Velocity vector.
		/// @see Vector
		virtual const Vector &vector(void) const { return _velocity; }
		
		/// @brief Set velocity vector.
		/// @param velocity Velocity vector.
		/// @see Vector
		virtual void set(const Vector &velocity) { _velocity = velocity; }
		
		/// @brief Get velocity in x dimension.
		/// @return Velocity in x dimension.
		virtual float vx(void) const { return _velocity.x(); }
		
		/// @brief Get velocity in y dimension.
		/// @return Velocity in y dimension.
		virtual float vy(void) const { return _velocity.y(); }
		
		/// @brief Get velocity in z dimension.
		/// @return Velocity in z dimension.
		virtual float vz(void) const { return _velocity.z(); }
		
		/// @brief Set velocity in x dimension.
		/// @param vx Velocity in x dimension to set.
		virtual void set_vx(float vx) { _velocity.set_x(vx); }
		
		/// @brief Set velocity in y dimension.
		/// @param vy Velocity in y dimension to set.
		virtual void set_vy(float vy) { _velocity.set_y(vy); }
		
		/// @brief Set velocity in z dimension.
		/// @param vz Velocity in z dimension to set.
		virtual void set_vz(float vz) { _velocity.set_z(vz); }
		
		/// @brief Change velocity by a.
		/// @param a Difference to apply.
		/// @see Vector
		virtual void accelerate(const Vector &a) { _velocity += a; }
		
		/// @brief Change velocity in x dimension by ax.
		/// @param ax Difference in x dimension to apply.
		virtual void accelerate_x(float ax) { _velocity.set_x(_velocity.x() + ax); }
		
		/// @brief Change velocity in y dimension by ay.
		/// @param ay Difference in y dimension to apply.
		virtual void accelerate_y(float ay) { _velocity.set_y(_velocity.y() + ay); }
		
		/// @brief Change velocity in z dimension by az.
		/// @param az Difference in z dimension to apply.
		virtual void accelerate_z(float az) { _velocity.set_z(_velocity.z() + az); }
	};
};

#endif  // WATERY_VELOCITY_H
