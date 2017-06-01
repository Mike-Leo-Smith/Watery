//
// Created by Mike Smith on 2017/5/26.
//

#ifndef WATERY_COLLISION_EVENT_H
#define WATERY_COLLISION_EVENT_H

#include "message.h"
#include "../Scene/object.h"

namespace watery
{
	class CollisionEvent : public Message
	{
	private:
		std::shared_ptr<Object> _object1;
		std::shared_ptr<Object> _object2;
	
	public:
		CollisionEvent(std::shared_ptr<Object> object1, std::shared_ptr<Object> object2, Microsecond time_out = COLLISION_EVENT_DEFAULT_TIME_OUT)
				: Message("collision_event", time_out), _object1(object1), _object2(object2) {}
		virtual ~CollisionEvent(void) override {}
		virtual std::shared_ptr<Object> object1(void) { return _object1; }
		virtual std::shared_ptr<Object> object2(void) { return _object2; }
	};
}

#endif  // WATERY_COLLISION_EVENT_H
