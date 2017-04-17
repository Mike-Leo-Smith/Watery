//
// Created by Mike Smith on 2017/4/17.
//

#include "system.h"

namespace watery
{
	void System::handle_message(Message *message)
	{
		switch (message->type())
		{
		case MESSAGE_KEYBOARD_EVENT:
			_handle_keyboard_message(message);
			break;
		
		case MESSAGE_MOUSE_EVENT:
			_handle_mouse_message(message);
			break;
		
		default:
			delete message;     // Delete useless message.
			break;
		}
	}
}