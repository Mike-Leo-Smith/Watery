//
// Created by Mike Smith on 2017/5/26.
//

#ifndef WATERY_DYING_EVENT_H
#define WATERY_DYING_EVENT_H

#include "../Scene/object.h"
#include "message.h"

namespace watery
{
	class DyingEvent : public Message
	{
	private:
		std::shared_ptr<Object> _object;
	
	public:
		DyingEvent(std::shared_ptr<Object> object, Microsecond time_out = DYING_EVENT_DEFAULT_TIME_OUT)
				: Message("dying_event", time_out), _object(object) {}
		virtual ~DyingEvent(void) override {}
		virtual std::shared_ptr<Object> object(void) { return _object; }
	};
}

#endif  // WATERY_DYING_EVENT_H
