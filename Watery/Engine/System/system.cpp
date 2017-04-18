//
// Created by Mike Smith on 2017/4/17.
//

#include "system.h"

namespace watery
{
	void System::_handle_message(void)
	{
		Message *message = _retrieve_message();
		
		if (message == nullptr)
		{
			return;
		}
		
		if (message->time_out())
		{
			delete(message);
			return;
		}
		
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