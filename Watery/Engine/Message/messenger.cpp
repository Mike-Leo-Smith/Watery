//
// Created by Mike Smith on 2017/4/17.
//

#include "messenger.h"

namespace watery
{
	std::vector<Message *> &Messenger::retrieve(void)
	{
		_messages.clear();
		
		while (!_message_bus.empty())
		{
			_messages.push_back(_message_bus.retrieve());
		}
		return _messages;
	}
}