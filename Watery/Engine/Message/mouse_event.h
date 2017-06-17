//
// Created by Mike Smith on 2017/5/9.
//

#ifndef WATERY_MOUSE_EVENT_H
#define WATERY_MOUSE_EVENT_H

#include "message.h"
#include "../../Framework/Mathematics/vector.h"

namespace watery
{
	class MouseEvent : public Message
	{
	private:
		Vector _position;
		bool _left_down;
		bool _right_down;
		
	public:
		MouseEvent(const Vector &position, bool left_down, bool right_down, Microsecond time_out = KEYBOARD_EVENT_DEFAULT_TIME_OUT)
				: Message("mouse_event", time_out), _position(position), _left_down(left_down), _right_down(right_down) {}
		virtual ~MouseEvent(void) override {}
		const Vector &position(void) const { return _position; }
		bool left_down(void) const { return _left_down; }
		bool right_down(void) const { return _right_down; }
	};
}

#endif  // WATERY_MOUSE_EVENT_H
