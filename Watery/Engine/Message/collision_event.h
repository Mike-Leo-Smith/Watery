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
		Object *_object1;
		Object *_object2;
	
	public:
		CollisionEvent(Object *object1, Object *object2, Microsecond time_out = COLLISION_DEFAULT_TIME_OUT)
				: Message("collision_event", time_out) {}
		virtual ~CollisionEvent(void) override {}
		virtual Object *object1(void) { return _object1; }
		virtual Object *object2(void) { return _object2; }
	};
}

#endif  // WATERY_COLLISION_EVENT_H
