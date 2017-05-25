//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_MESSENGER_H
#define WATERY_MESSENGER_H

#include "message_bus.h"

namespace watery
{
	class Messenger
	{
	private:
		MessageBus &_message_bus;
		std::vector<Message *> _messages;
		
	public:
		Messenger(void) : _message_bus(MessageBus::instance()) {}
		virtual ~Messenger(void) {}
		virtual std::vector<Message *> &retrieve(void);
		virtual void dispatch(Message *message) { _message_bus.dispatch(message); }
	};
}

#endif  // WATERY_MESSENGER_H
