//
// Created by Mike Smith on 2017/4/17.
//

#include "input.h"
#include "../Message/keyboard_message.h"

namespace watery
{
	void Input::_updating_tasks(void)
	{
		_handle_message();
		
		if (_window.key_down(KEY_UP)) { _dispatch_message(new KeyboardMessage(KEY_UP)); }
		if (_window.key_down(KEY_DOWN)) { _dispatch_message(new KeyboardMessage(KEY_DOWN)); }
		if (_window.key_down(KEY_LEFT)) { _dispatch_message(new KeyboardMessage(KEY_LEFT)); }
		if (_window.key_down(KEY_RIGHT)) { _dispatch_message(new KeyboardMessage(KEY_RIGHT)); }
	}
}