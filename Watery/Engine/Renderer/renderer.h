//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_RENDERER_H
#define WATERY_RENDERER_H

#include <nameser.h>
#include "../../Framework/Window/window.h"
#include "../System/system.h"

namespace watery
{
	class Renderer : public System
	{
	private:
		Window &_window;
	
	protected:
		virtual void _updating_tasks(void) override;
	
	public:
		Renderer(Microsecond interval = RENDERER_DEFAULT_UPDATE_INTERVAL);
	};
}

#endif  // WATERY_RENDERER_H
