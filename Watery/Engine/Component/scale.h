//
// Created by Mike Smith on 2017/5/31.
//

#ifndef WATERY_SCALE_H
#define WATERY_SCALE_H

#include "component.h"

namespace watery
{
	class Scale : public Component
	{
	private:
		float _scale;
	
	public:
		Scale(float scale) : Component("scale"), _scale(scale) {}
		virtual ~Scale(void) override {}
		virtual float scale(void) const { return _scale; }
		virtual void multiply(float multiplier) { _scale *= multiplier; }
		virtual void set_scale(float scale) { _scale = scale; }
	};
}

#endif  // WATERY_SCALE_H
