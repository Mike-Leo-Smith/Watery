/// @file component.h
/// @brief Header file for class Component.
/// @author ZSK
/// @date April 17, 2017

#ifndef WATERY_COMPONENT_H
#define WATERY_COMPONENT_H

#include <string>

namespace watery
{
	/// @brief Base component for objects.
	/// @see Object
	class Component
	{
	private:
		/// @brief Type string of the concrete component.
		std::string _type;
		
		/// @brief Whether a component is enabled.
		bool _enabled;
	
	public:
		/// @brief Construct a component of a certain type.
		/// @note Never construct a base component by yourself, but use the interfaces via Object or ComponentFactory to create concrete components.
		/// @see Object
		/// @see ComponentFactory
		Component(const std::string &type = "undefined") : _type(type), _enabled(true) {}
		
		/// @brief Destructor.
		virtual ~Component(void) {}
		
		/// @brief Get the type string of the concrete component.
		/// @return Type string of the concrete component.
		virtual const std::string &type(void) const { return _type; }
		
		/// @brief Disable a component.
		virtual void disable(void) { _enabled = false; }
		
		/// @brief Enable a component.
		virtual void enable(void) { _enabled = true; }
		
		/// @brief Test whether a component is enabled.
		/// @return Whether a component is enabled.
		virtual bool enabled(void) const { return _enabled; }
	};
}

#endif  // WATERY_COMPONENT_H
