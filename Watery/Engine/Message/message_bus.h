//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_MESSAGE_BUS_H
#define WATERY_MESSAGE_BUS_H

#include <queue>
#include "message.h"

namespace watery
{
	// Singleton message bus.
	class MessageBus
	{
	private:
		std::queue<Message *>  _message_queue;
		
		// Forbidden functions.
		MessageBus(void) {}
		MessageBus(const MessageBus &) = delete;
		MessageBus(MessageBus &&) = delete;
		~MessageBus(void) {}
		MessageBus &operator=(const MessageBus &) = delete;
		
	public:
		bool empty(void) const { return _message_queue.empty(); }
		Message *retrieve(void);
		void dispatch(Message *message);
		
		// Get the singleton instance.
		static MessageBus &instance(void);
	};
}

#endif  // WATERY_MESSAGE_BUS_H
