/// @file animation.h
/// @brief Header file for class Animation.
/// @author Mike Smith
/// @date May 25, 2017

#ifndef WATERY_ANIMATION_H
#define WATERY_ANIMATION_H

#include <memory>
#include "component.h"
#include "../Scene/object.h"

namespace watery
{
	/// @brief Animation component for objects.
	/// @note This is an abstract class. Concrete animations are derived from it.
	/// @see Component
	class Animation : public Component
	{
	public:
		/// @brief Default constructor.
		/// @see Component
		Animation(void) : Component("animation") {}
		
		/// @brief Destructor.
		virtual ~Animation(void) override {}
		
		/// @brief Interface for concrete animation steps.
		/// @param parent Pointer to the container object.
		/// @note Override this function in the derivative class so that the animation can take effects.
		/// @see Object
		virtual void animate(std::shared_ptr<Object> parent) = 0;
	};
}

#endif  // WATERY_ANIMATION_H
