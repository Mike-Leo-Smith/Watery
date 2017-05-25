//
// Created by Mike Smith on 2017/5/25.
//

#ifndef WATERY_AL_AUDIO_WRAPPER_H
#define WATERY_AL_AUDIO_WRAPPER_H

#include "../../Framework/Audio/al_audio.h"
#include "resource_wrapper.h"

namespace watery
{
	class ALAudioWrapper : public ResourceWrapper
	{
	private:
		ALAudio *_audio;
	
	public:
		ALAudioWrapper(const std::string &file_name);
		virtual ~ALAudioWrapper(void) override { delete _audio; }
		virtual void *data(void) override { return _audio; }
	};
}

#endif  // WATERY_AL_AUDIO_WRAPPER_H
