//
// Created by Mike Smith on 2017/5/26.
//

#ifndef WATERY_LOGIC_H
#define WATERY_LOGIC_H

#include <gl/glew.h>
#include "../../Watery/Engine/System/system.h"
#include "../../Watery/Engine/Scene/world.h"

constexpr watery::Microsecond LOGIC_UPDATE_INTERVAL = 15000;
class Logic : public watery::System
{
private:
	watery::World &_world;
	watery::Window &_window;
	
	virtual void update_camera(void);

protected:
	virtual void handle_keyboard_event(watery::KeyboardEvent *message) override;
	virtual void handle_collision_event(watery::CollisionEvent *message) override;
	virtual void handle_dying_event(watery::DyingEvent *message) override;
	virtual void do_updating_tasks(void) override;

public:
	Logic(watery::Microsecond update_interval = LOGIC_UPDATE_INTERVAL)
			: System("logic", update_interval), _world(watery::World::instance()), _window(watery::Window::instance()) {}
	bool is_type(const std::string &name, const std::string &type) { return name.find(type) != -1; }
	virtual ~Logic(void) override {}
};

#endif  // WATERY_LOGIC_H
