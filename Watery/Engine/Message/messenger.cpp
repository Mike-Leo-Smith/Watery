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
			Message *message = _message_bus.retrieve();
			
			if (message == nullptr)
			{
				continue;                       // Ignore null pointers (if exists).
			}
			else if (message->time_out())
			{
				delete message;                 // Delete expiring messages.
				continue;
			}
			else
			{
				_messages.push_back(message);   // Collect this piece of message.
			}
		}
		return _messages;
	}
}