//
// Created by Mike Smith on 2017/5/5.
//

#ifndef WATERY_SOUND_H
#define WATERY_SOUND_H

#include <map>
#include "../System/system.h"
#include "../../Framework/Audio/al_audio.h"

namespace watery
{
	class Sound : public System
	{
	private:
		std::map<std::string, ALAudio *> _sounds;
	
	protected:
	
	public:
		Sound(const std::string &name = "Sound", Microsecond interval = SOUND_DEFAULT_UPDATE_INTERVAL)
				: System(name, interval) {}
	};
}

#endif  // WATERY_SOUND_H
