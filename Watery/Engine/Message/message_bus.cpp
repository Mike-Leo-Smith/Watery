//
// Created by Mike Smith on 2017/4/17.
//

#include "message_bus.h"

namespace watery
{
	Message *MessageBus::retrieve(void)
	{
		if (_message_queue.empty())
		{
			return nullptr;
		}
		else
		{
			Message *message = _message_queue.front();
			_message_queue.pop();
			return message;
		}
	}
	
	void MessageBus::dispatch(Message *message)
	{
		_message_queue.push(message);
	}
	
	MessageBus &MessageBus::instance(void)
	{
		static MessageBus message_bus;
		return message_bus;
	}
}
