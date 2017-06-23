/// @file scale.h
/// @brief Header file for class Scale.
/// @author ZSK
/// @date May 31, 2017

#ifndef WATERY_SCALE_H
#define WATERY_SCALE_H

#include "component.h"

namespace watery
{
	/// @brief Scale component for objects.
	/// @see Component
	/// @see Object
	class Scale : public Component
	{
	private:
		/// @brief Scale multiplier.
		float _scale;
	
	public:
		/// @brief Construct from a demanded scale multiplier.
		/// @param scale Demanded scale multiplier.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		Scale(float scale) : Component("scale"), _scale(scale) {}
		
		/// @brief Destructor.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual ~Scale(void) override {}
		
		/// @brief Get scale multiplier.
		/// @return Scale multiplier.
		virtual float scale(void) const { return _scale; }
		
		/// @brief Change the scale by multiplying the multiplier.
		/// @param multiplier Change of scale to multiply.
		virtual void multiply(float multiplier) { _scale *= multiplier; }
		
		/// @brief Set scale.
		/// @param scale Demanded scale.
		virtual void set_scale(float scale) { _scale = scale; }
	};
}

#endif  // WATERY_SCALE_H
