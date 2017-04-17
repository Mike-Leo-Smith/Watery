//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_MESSAGE_H
#define WATERY_MESSAGE_H

namespace watery
{
	enum MessageType
	{
		MESSAGE_UNDEFINED,
		
		MESSAGE_KEYBOARD_EVENT,
		MESSAGE_MOUSE_EVENT,
		
		MESSAGE_TYPE_COUNT
	};
	
	class Message
	{
	private:
		MessageType _type;
	
	public:
		Message(MessageType type = MESSAGE_UNDEFINED) : _type(type) {}
		virtual ~Message(void) {}
		virtual MessageType type(void) const { return _type; }
	};
}

#endif  // WATERY_MESSAGE_H
