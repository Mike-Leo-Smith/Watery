//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_SYSTEM_H
#define WATERY_SYSTEM_H

#include "../Message/messenger.h"

namespace watery
{
	class System
	{
	private:
		Messenger _messenger;
		
		// Functions handling messages. Pass them on by default.
		virtual void _handle_keyboard_message(Message *message) { _messenger.dispatch(message); }
		virtual void _handle_mouse_message(Message *message) { _messenger.dispatch(message); }
		
	public:
		System(void) {}
		virtual ~System(void) {}
		virtual void handle_message(Message *message);
	};
}

#endif  // WATERY_SYSTEM_H
