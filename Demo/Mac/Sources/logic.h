/// @file logic.h
/// @brief Header for class Logic.
/// @author ZYF
/// @date May 3, 2017

#ifndef WATERY_LOGIC_H
#define WATERY_LOGIC_H

#include <GL/glew.h>
#include "../../../Watery/Engine/System/system.h"
#include "../../../Watery/Engine/Scene/world.h"

constexpr watery::Microsecond LOGIC_UPDATE_INTERVAL = 15000;

/// @brief Logic of the game.
/// @see System
class Logic : public watery::System
{
private:
	watery::World &_world;
	watery::Window &_window;
	
	/// @brief Update camera position when move.
	virtual void update_camera(void);

protected:
	
	/// @brief Do something when keyborads are pressed.
	/// @param message Specific information about keyboards.
	/// @see KeyboardEvent
	/// @see Message
	virtual void handle_keyboard_event(watery::KeyboardEvent *message) override;
	
	/// @brief Do something when mouse moves.
	/// @param message Specific information about mouse.
	/// @see MouseEvent
	/// @see Message
	virtual void handle_mouse_event(watery::MouseEvent *message) override;
	
	/// @brief Do something when two objects collide.
	/// @param message Specific information about collision.
	/// @see CollisionEvent
	/// @see Message
	virtual void handle_collision_event(watery::CollisionEvent *message) override;
	
	/// @brief Do something when some object is dying.
	/// @param message Specific information about dying.
	/// @see DyingEvent
	/// @see Message
	virtual void handle_dying_event(watery::DyingEvent *message) override;
	
	/// @brief Do something when the camera moves.
	virtual void do_updating_tasks(void) override;

public:
	/// @brief Constructor.
	/// @see Window
	/// @see World
	Logic(watery::Microsecond update_interval = LOGIC_UPDATE_INTERVAL)
			: System("logic", update_interval), _world(watery::World::instance()), _window(watery::Window::instance()) {}
	
	bool is_type(const std::string &name, const std::string &type) { return name.find(type) != -1; }
	
	/// @brief Destructor.
	/// @note Nothing need to do.
	virtual ~Logic(void) override {}
};

#endif  // WATERY_LOGIC_H
