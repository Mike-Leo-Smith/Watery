/// @file random_move_animation.h
/// @brief Header file for class RandomMoveAnimation.
/// @author ZYF
/// @date May 29, 2017

#ifndef WATERY_RANDOM_MOVE_ANIMATION_H
#define WATERY_RANDOM_MOVE_ANIMATION_H

#include <random>
#include "animation.h"
#include "../Timer/timer.h"

namespace watery
{
	/// @brief Random move animation component for objects.
	/// @see Animation
	/// @see Component
	/// @see Object
	class RandomMoveAnimation : public Animation
	{
	private:
		/// @brief Timer for step indexing.
		/// @see Timer
		Timer _timer;
	
	public:
		/// @brief Construct from a demanded interval.
		/// @param interval Demanded interval in microseconds.
		/// @see Animation
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		RandomMoveAnimation(Microsecond interval = 1000000) { _timer.set_time_out(interval); }
		
		/// @brief Destructor
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual ~RandomMoveAnimation(void) override {}
		
		/// @brief Animation steps.
		/// @param parent Pointer to the container object.
		/// @see Animation
		/// @see Object
		virtual void animate(std::shared_ptr<Object> parent) override;
		
	};
}

#endif // WATERY_RANDOM_MOVE_ANIMATION_H
