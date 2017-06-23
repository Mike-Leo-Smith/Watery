/// @file shrink_animation.h
/// @brief Header file for class ShrinkAnimation
/// @author ZSK
/// @date May 31, 2017

#ifndef WATERY_SHRINK_ANIMATION_H
#define WATERY_SHRINK_ANIMATION_H

#include "animation.h"
#include "../Timer/timer.h"

namespace watery
{
	/// @brief Shrink animation component for objects.
	/// @see Object
	/// @see Component
	class ShrinkAnimation : public Animation
	{
	private:
		/// @brief Timer for step indexing.
		/// @see Timer
		Timer _timer;
	
	public:
		/// @brief Construct from demanded interval.
		/// @param interval Demanded animation interval.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		ShrinkAnimation(Microsecond interval = 30000) : _timer(interval) {}
		
		/// @brief Destructor.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual ~ShrinkAnimation(void) override {}
		
		/// @brief Animation steps.
		/// @param parent Pointer to the container object.
		/// @see Object
		/// @see Animation
		virtual void animate(std::shared_ptr<Object> parent) override;
	};
}

#endif  // WATERY_SHRINK_ANIMATION_H
