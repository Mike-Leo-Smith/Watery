/// @file lifetime.h
/// @brief Header file for class Lifetime
/// @author ZYF
/// @date May 26, 2017

#ifndef WATERY_LIFETIME_H
#define WATERY_LIFETIME_H

#include "component.h"
#include "../Timer/timer.h"

namespace watery
{
	/// @brief Lifetime component for objects.
	/// @see Object
	/// @see Component
	class Lifetime : public Component
	{
	private:
		/// @brief Timer for lifetime control.
		Timer _timer;
	
	public:
		/// @brief Construct a lifetime component with demanded lifetime.
		/// @param life Demanded lifetime in microseconds.
		/// @see Component
		/// @see Timer
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see ComponentFactory
		/// @see Object
		Lifetime(Microsecond life) : Component("lifetime"), _timer(life) { _timer.reset(); }
		
		/// @brief Destructor.
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		/// @see ComponentFactory
		/// @see Object
		virtual ~Lifetime(void) override {}
		
		/// @brief Set lifetime.
		/// @param life Lifetime to set.
		/// @note When the lifetime is set, the timer is reset.
		/// @see TImer
		virtual void set_lifetime(Microsecond life) { _timer.set_time_out(life), _timer.reset(); }
		
		/// @brief Test whether a object has run out of its lifetime.
		/// @return Whether a object has run out of its lifetime.
		/// @note This function is called by Scene system which automatically removes dead objects.
		/// @see Scene
		virtual bool dead(void) { return _timer.time_out(); }
	};
}

#endif  // WATERY_LIFETIME_H
