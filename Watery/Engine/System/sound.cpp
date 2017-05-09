//
// Created by Mike Smith on 2017/5/9.
//

#include "sound.h"
#include "../Component/audio.h"

namespace watery
{
	void Sound::updating_tasks(void)
	{
		handle_message();
		
		for (const auto &item : _world.objects())
		{
			const Object *object = item.second;
			
			if (object->bound(COMPONENT_AUDIO))
			{
				const ALAudio *audio = static_cast<const Audio *>(object->component(COMPONENT_AUDIO))->audio();
				
				if (object->enabled(COMPONENT_AUDIO))
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
	}
}