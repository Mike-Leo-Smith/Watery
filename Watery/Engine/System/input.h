//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_INPUT_H
#define WATERY_INPUT_H

#include "system.h"
#include "../Message/message.h"
#include "../../Framework/Window/window.h"
#include "../Configure/configure.h"

namespace watery
{
	class Input : public System
	{
	private:
		Window &_window;
	
	protected:
		virtual void do_updating_tasks(void) override;
	
	public:
		Input(const std::string &name = "Input", Microsecond interval = INPUT_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval), _window(Window::instance()) {}
		virtual ~Input(void) {}
	};
}

#endif  // WATERY_INPUT_H
