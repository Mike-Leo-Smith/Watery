/// @file helix_move_animation.h
/// @brief Header file for class HelixMoveAnimation.
/// @author ZYF
/// @date May 28, 2017

#ifndef WATERY_HELIX_MOVE_ANIMATION_H
#define WATERY_HELIX_MOVE_ANIMATION_H

#include "animation.h"
#include "../Timer/timer.h"

namespace watery
{
	/// @brief Helix move animation component for objects.
	/// @see Animation
	/// @see Component
	/// @see Object
	class HelixMoveAnimation : public Animation
	{
	private:
		/// @brief Timer for step indexing.
		/// @see Timer
		Timer _timer;
	
	public:
		/// @brief Animation steps.
		/// @param parent Pointer to the container object.
		/// @see Animation
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual void animate(std::shared_ptr<Object> parent) override;
		
		/// @brief Destructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see Object
		/// @see ComponentFactory
		virtual ~HelixMoveAnimation(void) override {}
	};
}

#endif  // WATERY_HELIX_MOVE_ANIMATION_H
