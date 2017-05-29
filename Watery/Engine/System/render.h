//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_RENDER_H
#define WATERY_RENDER_H

#include "system.h"
#include "../Scene/world.h"
#include "../Mathematics/matrix.h"
#include "../../Framework/Window/window.h"
#include "../../Framework/Graphics/gl_graphics.h"

namespace watery
{
	class Render : public System
	{
	private:
		Window &_window;
		World &_world;
		GLGraphics _graphics;
		
		virtual const Matrix get_proj_matrix(void) const;
		virtual const Matrix get_view_matrix(void) const;
		virtual void render_scene(void);
	
	protected:
		virtual void do_updating_tasks(void) override;
		
	public:
		Render(const std::string &name = "render", Microsecond interval = RENDER_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval), _window(Window::instance()), _world(World::instance()) {}
		virtual ~Render(void) {}
	};
}

#endif  // WATERY_RENDER_H
