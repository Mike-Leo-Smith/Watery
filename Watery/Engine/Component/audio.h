//
// Created by Mike Smith on 2017/5/7.
//

#ifndef WATERY_AUDIO_H
#define WATERY_AUDIO_H

#include "../../Framework/Audio/al_audio.h"
#include "component.h"

namespace watery
{
	class Audio : public Component
	{
	private:
		ALAudio *_audio;
	
	public:
		Audio(ALAudio *audio = nullptr) : Component(COMPONENT_AUDIO), _audio(audio) {}
		virtual ~Audio(void) {}
		virtual void bind_audio(ALAudio *audio) { _audio = audio; }
		virtual const ALAudio *audio(void) const { return _audio; }
		virtual ALAudio *audio(void) { return _audio; }
	};
}

#endif  // WATERY_AUDIO_H
