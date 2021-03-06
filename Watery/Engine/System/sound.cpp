//
// Created by Mike Smith on 2017/5/9.
//

#include "sound.h"

namespace watery
{
	void Sound::do_updating_tasks(void)
	{
		handle_message();
#ifndef _WIN32
		for (const auto &item : _world.objects())
		{
			const std::shared_ptr<Object> object = item.second;
			
			if (object->bound("audio"))
			{
				const ALAudio *audio = static_cast<const Audio *>(object->component("audio"))->audio();
				
				if (object->enabled("audio"))
				{
					if (!audio->playing())
					{
						audio->play(false);
					}
				}
				else
				{
					audio->pause();
				}
			}
		}
#endif
	}
}