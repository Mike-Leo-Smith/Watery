//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_RENDER_H
#define WATERY_RENDER_H

#include "../../Framework/Window/window.h"
#include "system.h"
#include "../World/world.h"
#include "../Mathematics/matrix.h"
#include "../../Framework/Graphics/gl_graphics.h"

namespace watery
{
	class Render : public System
	{
	private:
		Window &_window;
		World &_world;
		GLGraphics _graphics;
	
	protected:
		virtual void do_updating_tasks(void) override;
		virtual const Matrix get_proj_matrix(void) const;
		
	public:
		Render(const std::string &name = "Render", Microsecond interval = RENDERER_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval), _window(Window::instance()), _world(World::instance()) {}
		virtual ~Render(void) {}
	};
}

#endif  // WATERY_RENDER_H
