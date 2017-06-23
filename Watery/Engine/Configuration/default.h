/// @file default.h
/// @brief Header file for default settings.
/// @author ZSK
/// @date May 5, 2017

#ifndef WATERY_CONFIGURE_H
#define WATERY_CONFIGURE_H

#include "../../Framework/Clock/clock.h"

namespace watery
{
	/// @brief Default message timeout in microseconds.
	constexpr Microsecond MESSAGE_DEFAULT_TIMEOUT = 50000;
	
	/// @brief Default keyboard event timeout in microseconds.
	constexpr Microsecond KEYBOARD_EVENT_DEFAULT_TIMEOUT = 50000;
	
	/// @brief Default mouse event timeout in microseconds.
	constexpr Microsecond MOUSE_EVENT_DEFAULT_TIMEOUT = 50000;
	
	/// @brief Default collision event timeout in microseconds.
	constexpr Microsecond COLLISION_EVENT_DEFAULT_TIMEOUT = 100000;
	
	/// @brief Default dying event timeout in microseconds.
	constexpr Microsecond DYING_EVENT_DEFAULT_TIMEOUT = 100000;
	
	// System update intervals.
	constexpr Microsecond SYSTEM_DEFAULT_UPDATE_INTERVAL = 50000;
	constexpr Microsecond INPUT_DEFAULT_UPDATE_INTERVAL = 50000;
	constexpr Microsecond RENDER_DEFAULT_UPDATE_INTERVAL = 16000;
	constexpr Microsecond SOUND_DEFAULT_UPDATE_INTERVAL = 50000;
	constexpr Microsecond SCENE_DEFAULT_UPDATE_INTERVAL = 20000;
	
	// System timer calibration frequency.
	constexpr int SYSTEM_TIMER_CALIBRATION_FREQUENCY = 10;
}

#endif  // WATERY_CONFIGURE_H
