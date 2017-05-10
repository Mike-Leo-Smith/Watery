//
// Created by Mike Smith on 2017/5/10.
//

#include "frame_animation.h"

namespace watery
{
	void FrameAnimation::load(const std::vector<GLTexture *> frames, Microsecond interval)
	{
		_frames = frames;
		_interval = interval;
	}
	
	GLTexture *FrameAnimation::frame(void)
	{
		GLTexture *texture = nullptr;
		
		if (_frames.size() != 0 && _interval != 0)
		{
			texture = _frames[_timer.elapsed_time() / _interval % _frames.size()];
		}
		
		return texture;
	}
}