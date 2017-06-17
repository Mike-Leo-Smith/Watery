/// @file component_factory.h
/// @brief Header file for class ComponentFactory.
/// @author Mike Smith
/// @date May 7, 2017.

#ifndef WATERY_COMPONENT_FACTORY_H
#define WATERY_COMPONENT_FACTORY_H

#include <set>
#include "position.h"
#include "velocity.h"
#include "audio.h"
#include "shader.h"
#include "texture.h"
#include "vertex_array.h"
#include "health.h"
#include "../Resource/resource_manager.h"

namespace watery
{
	/// @brief Factory for creating components.
	/// @note It is a singleton and should not be used directly but used via objects.
	/// @see Object
	/// @see Component
	class ComponentFactory
	{
	private:
		/// @brief Created components.
		/// @see Component
		std::set<Component *> _components;
		
		/// @brief Reference to the resource manager.
		/// @see ResourceManager
		ResourceManager &_resource;
		
		/// @brief Hidden default constructor for singleton implementation.
		/// @see ResourceManager
		ComponentFactory(void) : _resource(ResourceManager::instance()) {}
		
		/// @brief Deleted copy constructor for singleton implementation.
		ComponentFactory(const ComponentFactory &) = delete;
		
		/// @brief Deleted move constructor for singleton implementation.
		ComponentFactory(ComponentFactory &&) = delete;
		
		/// @brief Deleted assignment operator for singleton implementation.
		ComponentFactory &operator=(const ComponentFactory &) = delete;
		
		/// @brief Destructor.
		~ComponentFactory(void) { destroy_all(); }
	
	public:
		/// @brief Create a component.
		/// @note This function should not be called directly. Use it via the interfaces of Object.
		/// @see Object
		/// @see Component
		/// @param type Type of the component to create.
		/// @param arg Arguments encoded in std::string.
		/// @return The newly created component.
		Component *create_component(const std::string &type, const std::string &arg);
		
		/// @brief Destroy a component.
		/// @note This function should not be called directly. Use it via the interfaces of Object.
		/// @see Object
		/// @see Component
		/// @param component Pointer to the component to be destroyed.
		void destroy_component(Component *component);
		
		/// @brief Destroy all the created components.
		/// @note This function should not be called directly. It is typically used for clean-ups before level loading.
		void destroy_all(void);
		
		/// @brief Get the instance of the singleton.
		/// @return Reference to the instance of the factory.
		static ComponentFactory &instance(void);
	};
}

#endif  // WATERY_COMPONENT_FACTORY_H
