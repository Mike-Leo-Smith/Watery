/// @file weapon.h
/// @brief Header file for class Weapon
/// @author ZYF
/// @date May 27, 2017

#ifndef WATERY_WEAPON_H
#define WATERY_WEAPON_H

#include "component.h"
#include "../Scene/world.h"
#include "../Timer/timer.h"

namespace watery
{
	/// @brief Weapon component for objects.
	/// @see Object
	/// @see Component
	class Weapon : public Component
	{
	protected:
		/// @brief Reference to the object world.
		/// @see World
		World &_world;
		
		/// @brief Weapon type.
		std::string _weapon_type;
		
		/// @brief Count of generated bullets for naming.
		static int _bullet_count;
		
		/// @brief Timer for fire interval.
		/// @see Timer
		Timer _timer;
		
		/// @brief Timer for weapon changing.
		/// @see Timer
		Timer _life;
		
		/// @brief Whether a weapon fires automatically.
		bool _is_auto;
	
	public:
		/// @brief Construct from demanded weapon type.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		Weapon(const std::string &weapon_type, bool is_auto)
				: Component("weapon"), _world(World::instance()), _timer(is_auto ? 600000 : 200000), _life(3000000), _weapon_type(weapon_type), _is_auto(is_auto) {}
		
		/// @brief Get whether the weapon is automatic or not.
		/// @return Whether the weapon is automatic.
		virtual bool is_auto(void) { return _is_auto; }
		
		/// @brief Set weapon type.
		/// @param weapon_type Weapon type.
		/// @param is_auto Whether the weapon is automatic.
		virtual void set_type(const std::string &weapon_type, bool is_auto);
		
		/// @brief Fire.
		/// @param owner Pointer to the owner object.
		/// @see Object
		virtual void fire(std::shared_ptr<Object> owner);
		
		/// @brief Destructor.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual ~Weapon(void) override {}
	};
}

#endif //WATERY_WEAPON_H
