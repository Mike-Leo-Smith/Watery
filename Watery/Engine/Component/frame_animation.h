//
// Created by Mike Smith on 2017/5/10.
//

#ifndef WATERY_FRAME_ANIMATION_H
#define WATERY_FRAME_ANIMATION_H

#include <vector>
#include "component.h"
#include "../../Framework/Graphics/gl_texture.h"
#include "../Timer/timer.h"
#include "../../Framework/Graphics/gl_vertex_array.h"

namespace watery
{
	class FrameAnimation : public Component
	{
	private:
		std::vector<GLTexture *> _frames;
		Timer _timer;
		Microsecond _interval;
	
	public:
		FrameAnimation(const std::vector<GLTexture *> frames = std::vector<GLTexture *>(), Microsecond interval = 33333)
				: Component(COMPONENT_FRAME_ANIMATION), _frames(frames), _interval(interval) { _timer.reset(); }
		virtual ~FrameAnimation(void) {}
		virtual void load(const std::vector<GLTexture *> frames, Microsecond interval = 33333);
		virtual GLTexture *frame(void);
	};
}

#endif  // WATERY_FRAME_ANIMATION_H
