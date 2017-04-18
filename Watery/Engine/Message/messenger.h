//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_MESSENGER_H
#define WATERY_MESSENGER_H

#include "../../Middleware/MessageBus/message_bus.h"

namespace watery
{
	class Messenger
	{
	private:
		MessageBus &_message_bus;
		
	public:
		Messenger(void) : _message_bus(MessageBus::instance()) {}
		virtual ~Messenger(void) {}
		virtual Message *retrieve(void) { return _message_bus.retrieve(); }
		virtual void dispatch(Message *message) { _message_bus.dispatch(message); }
	};
}

#endif  // WATERY_MESSENGER_H
