//
// Created by Mike Smith on 2017/5/26.
//

#ifndef WATERY_CONSTRAINT_H
#define WATERY_CONSTRAINT_H

#include "component.h"
#include "../Scene/object.h"

namespace watery
{
	class Constraint : public Component
	{
	public:
		Constraint(void) : Component("constraint") {}
		virtual ~Constraint(void) {}
		virtual void constrain(Object *object, Object *target = nullptr) = 0;
	};
}

#endif  // WATERY_CONSTRAINT_H
