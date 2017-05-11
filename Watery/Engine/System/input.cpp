//
// Created by Mike Smith on 2017/4/17.
//

#include "input.h"

namespace watery
{
	void Input::do_updating_tasks(void)
	{
		handle_message();
		dispatch_message(new KeyboardMessage(_keyboard.status()));
	}
}