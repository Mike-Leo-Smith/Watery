//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_INPUT_H
#define WATERY_INPUT_H

#include "system.h"
#include "../Message/message.h"
#include "../../Framework/Window/window.h"
#include "../../Framework/HID/keyboard.h"
#include "../../Framework/HID/mouse.h"

namespace watery
{
	class Input : public System
	{
	private:
		Keyboard _keyboard;
		Mouse _mouse;
	
	protected:
		virtual void do_updating_tasks(void) override;
	
	public:
		Input(const std::string &name = "input", Microsecond interval = INPUT_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval) {}
		virtual ~Input(void) {}
	};
}

#endif  // WATERY_INPUT_H
