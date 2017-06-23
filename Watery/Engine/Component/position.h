/// @file position.h
/// @brief Header file for class Position.
/// @author ZSK
/// @date April 17, 2017

#ifndef WATERY_POSITION_H
#define WATERY_POSITION_H

#include "component.h"
#include "../../Framework/Mathematics/vector.h"

namespace watery
{
	/// @brief Position component for obejcts.
	/// @see Object
	/// @see Component
	class Position : public Component
	{
	private:
		/// @brief Position vector.
		/// @see Vector
		Vector _position;
	
	public:
		/// @brief Construct from a position vector.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see Vector
		/// @see Object
		/// @see ComponentFactory
		Position(const Vector &position = Vector()) : Component("position"), _position(position) {}
		
		/// @brief Destructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see object
		/// @see ComponentFactory
		virtual ~Position(void) override {}
		
		/// @brief Get the position vector.
		/// @return The position vector.
		virtual const Vector &vector(void) const { return _position; }
		
		/// @brief Set position by a position vector.
		/// @param position Position to set.
		/// @see Vector
		virtual void set(const Vector &position) { _position = position; }
		
		/// @brief Move by a vector.
		/// @param d Difference to apply.
		/// @see Vector
		virtual void move(const Vector &d) { _position += d; }
		
		/// @brief Move in x dimension by dx.
		/// @param dx Difference in x dimension to apply.
		virtual void move_x(float dx) { _position.set_x(_position.x() + dx); }
		
		/// @brief Move in y dimension by dy.
		/// @param dy Difference in y dimension to apply.
		virtual void move_y(float dy) { _position.set_y(_position.y() + dy); }
		
		/// @brief Move in z dimension by dz.
		/// @param dz Difference in z dimension to apply.
		virtual void move_z(float dz) { _position.set_z(_position.z() + dz); }
		
		/// @brief Get position in x dimension.
		/// @return Position in x dimension.
		virtual float x(void) const { return _position.x(); }
		
		/// @brief Get position in y dimension.
		/// @return Position in y dimension.
		virtual float y(void) const { return _position.y(); }
		
		/// @brief Get position in z dimension.
		/// @return Position in z dimension.
		virtual float z(void) const { return _position.z(); }
		
		/// @brief Set position in x dimension.
		/// @param x Position in x dimension.
		virtual void set_x(float x) { _position.set_x(x); }
		
		/// @brief Set position in y dimension.
		/// @param y Position in y dimension.
		virtual void set_y(float y) { _position.set_y(y); }
		
		/// @brief Set position in z dimension.
		/// @param z Position in z dimension.
		virtual void set_z(float z) { _position.set_z(z); }
	};
}

#endif  // WATERY_POSITION_H
