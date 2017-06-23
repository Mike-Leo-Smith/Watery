/// @file animation.h
/// @brief Header file for class Animation.
/// @author ZYF
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
	/// @see Object
	class Animation : public Component
	{
	public:
		/// @brief Default constructor.
		/// @see Component
		/// @see ComponentFactory
		/// @see Object
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		Animation(void) : Component("animation") {}
		
		/// @brief Destructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see ComponentFactory
		/// @see Object
		virtual ~Animation(void) override {}
		
		/// @brief Interface for concrete animation steps called by the Scene system.
		/// @param parent Pointer to the container object.
		/// @note Override this function in the derivative class so that the animation can take effects.
		/// @see Object
		/// @see Scene
		virtual void animate(std::shared_ptr<Object> parent) = 0;
	};
}

#endif  // WATERY_ANIMATION_H
