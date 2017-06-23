/// @file constraint.h
/// @brief Header file for class Constraint.
/// @author Mike Smith
/// @date May 26, 2017

#ifndef WATERY_CONSTRAINT_H
#define WATERY_CONSTRAINT_H

#include "component.h"
#include "../Scene/object.h"

namespace watery
{
	/// @brief Constraint component for objects.
	/// @note This is an abstract class. Concrete constraints are derived from it.
	/// @see Component
	/// @see Object
	class Constraint : public Component
	{
	public:
		/// @brief Default constructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see Component
		/// @see Object
		/// @see ComponentFactory
		Constraint(void) : Component("constraint") {}
		
		/// @brief Destructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see Object
		/// @see ComponentFactory
		virtual ~Constraint(void) {}
		
		/// @brief Interface for concrete constraint steps called by the Scene system.
		/// @param parent Pointer to the container object.
		/// @note Override this function in the derivative class so that the constraint can take effects.
		/// @see Object
		/// @see Scene
		virtual void constrain(std::shared_ptr<Object> parent) = 0;
	};
}

#endif  // WATERY_CONSTRAINT_H
