//
// Created by Mike Smith on 2017/5/25.
//

#include "scene.h"

void watery::Scene::do_updating_tasks(void)
{
	handle_message();
	detect_collisions();
	advance_status();
}
