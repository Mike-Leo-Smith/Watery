//
// Created by Mike Smith on 2017/4/17.
//

#include "input.h"
#include "../Message/keyboard_message.h"

namespace watery
{
	void Input::_handle_keyboard_message(Message *message)
	{
		delete message;
	}
	
	void Input::_handle_mouse_message(Message *message)
	{
		delete message;
	}
	
	void Input::_update(void)
	{
		_handle_message();
		
		if (_keyboard.key_down(KEY_UP)) { _dispatch_message(new KeyboardMessage(KEY_UP)); }
		if (_keyboard.key_down(KEY_DOWN)) { _dispatch_message(new KeyboardMessage(KEY_DOWN)); }
		if (_keyboard.key_down(KEY_LEFT)) { _dispatch_message(new KeyboardMessage(KEY_LEFT)); }
		if (_keyboard.key_down(KEY_RIGHT)) { _dispatch_message(new KeyboardMessage(KEY_RIGHT)); }
	}
}