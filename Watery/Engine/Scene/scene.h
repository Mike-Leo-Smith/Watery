//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_SCENE_H
#define WATERY_SCENE_H

#include <map>
#include <string>
#include "../System/system.h"
#include "../World/entity.h"
#include "../Camera/camera.h"
#include "../World/world.h"
#include "../Renderer/renderer.h"

namespace watery
{
	class Scene : public System
	{
	private:
		World _world;
		Camera _camera;
		Renderer _renderer;
	
	protected:
		virtual void _handle_keyboard_message(Message *message) override;
	
	public:
		Scene(const std::string &name = "Scene", Microsecond interval = SCENE_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval) {}
		virtual Camera &camera(void) { return _camera; }
	};
}

#endif  // WATERY_SCENE_H
