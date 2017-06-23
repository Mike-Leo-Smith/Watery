/// @file health.h
/// @brief Header for class Health.
/// @author Mike Smith
/// @date May 10, 2017

#ifndef WATERY_HEALTH_H
#define WATERY_HEALTH_H

#include "component.h"

namespace watery
{
	/// @brief Health component for objects.
	/// @see Component
	/// @see Object
	class Health : public Component
	{
	private:
		/// @brief Maximal value of health.
		float _maximum;
		
		/// @brief Current value of health.
		float _health;
	
	public:
		/// @brief Constructor.
		/// @param initial Initial value of health.
		/// @param maximum Maximal value of health.
		/// @note The constructor ensures that the initial health is no greater than the maximum.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see Object
		/// @see Component
		/// @see ComponentFactory
		Health(float initial, float maximum)
				: Component("health"), _health(initial <= maximum ? initial : maximum), _maximum(maximum) {}
		
		/// @brief Destructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see ComponentFactory
		/// @see Object
		virtual ~Health(void) override {}
		
		/// @breif Get current health.
		/// @return Current health.
		virtual float health(void) const { return _health; }
		
		/// @brief Get maximal health.
		/// @return Maximal health.
		virtual float maximum(void) const { return _maximum; }
		
		/// @brief Set current health.
		/// @param health Health value to set.
		/// @note This function ensures that current value is no greater than maximum and no less than 0.
		virtual void set_health(float health) { _health = (health <= _maximum ? (health >= 0 ? health : 0) : _maximum); }
		
		/// @brief Set maximal health.
		/// @param maximum Maximal health to set.
		/// @note This function ensures that current value is no less than current health and no less than 0.
		virtual void set_maximum(float maximum) { _maximum = (_maximum > 0 ? _maximum : 0), _health = (_health <= maximum ? _health : _maximum); }
		
		/// @brief Increase current health by val.
		/// @param val Difference to apply.
		/// @note This function ensures current health is no greater than maximum.
		virtual void increase(float val) { _health = (_health + val <= _maximum ? _health + val : _maximum); }
		
		/// @brief Decrease current health by val.
		/// @param val Difference to apply.
		/// @note This fuction ensures current health is no less than 0.
		virtual void decrease(float val) { _health = (_health - val >= 0 ? _health - val : 0); }
		
		/// @brief Test whether an object is dying.
		/// @return Whether an object is dying.
		/// @note This function is called by Scene system which sends a dying message if the object is dying.
		/// @see Scene
		/// @see DyingMessage
		virtual bool dying(void) const { return _health <= 1e-3; }
	};
}

#endif  // WATERY_HEALTH_H
