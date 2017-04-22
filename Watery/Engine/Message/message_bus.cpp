//
// Created by Mike Smith on 2017/4/17.
//

#include "message_bus.h"

namespace watery
{
	// Create the singleton instance.
	MessageBus *MessageBus::_instance = new MessageBus;
	
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
}