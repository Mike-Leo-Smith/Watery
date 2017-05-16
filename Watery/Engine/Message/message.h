//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_MESSAGE_H
#define WATERY_MESSAGE_H

#include <ctime>
#include <string>
#include <set>
#include "../Timer/timer.h"
#include "../../Framework/Clock/clock.h"
#include "../Configuration/default.h"

namespace watery
{
	enum MessageType
	{
		MESSAGE_UNDEFINED,
		
		MESSAGE_KEYBOARD_EVENT,
		MESSAGE_MOUSE_EVENT,
		MESSAGE_SCENE_EVENT,
		
		MESSAGE_TYPE_COUNT
	};
	
	class Message
	{
	private:
		MessageType _type;
		Timer _timer;
		std::set<std::string> _signatures;
		
	public:
		Message(MessageType type = MESSAGE_UNDEFINED, Microsecond time_out = MESSAGE_DEFAULT_TIME_OUT)
				: _type(type), _timer(time_out) { _timer.reset(); }
		virtual ~Message(void) {}
		virtual MessageType type(void) const { return _type; }
		virtual bool time_out(void) const { return _timer.time_out(); }
		virtual void sign(const std::string &system) { _signatures.emplace(system); }
		virtual bool signed_by(const std::string &system) { return (_signatures.count(system) != 0); }
		template<typename MESSAGE_TYPE> MESSAGE_TYPE *decode(void) { return static_cast<MESSAGE_TYPE *>(this); }
		template<typename MESSAGE_TYPE> const MESSAGE_TYPE *decode(void) const { return static_cast<const MESSAGE_TYPE *>(this); }
	};
}

#endif  // WATERY_MESSAGE_H
