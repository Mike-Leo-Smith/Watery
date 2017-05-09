//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_RENDERER_H
#define WATERY_RENDERER_H

#include "../../Framework/Window/window.h"
#include "system.h"
#include "../World/world.h"
#include "../../Data/Matrix/matrix.h"
#include "../../Framework/Graphics/gl_graphics.h"

namespace watery
{
	class Renderer : public System
	{
	private:
		Window &_window;
		const World &_world;
		GLGraphics _graphics;
	
	protected:
		virtual void updating_tasks(void) override;
		virtual const Matrix get_proj_matrix(void) const;
		
	public:
		Renderer(const std::string &name = "Render", Microsecond interval = RENDERER_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval), _window(Window::instance()), _world(World::instance()) {}
		virtual ~Renderer(void) {}
		virtual void init(const std::string &window_name, int width, int height);
	};
}

#endif  // WATERY_RENDERER_H
