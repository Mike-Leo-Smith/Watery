//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_AL_AUDIO_H
#define WATERY_AL_AUDIO_H

#include <OpenAL/al.h>
#include "al_initializer.h"

namespace watery
{
	class ALAudio
	{
	private:
		ALInitializer &_initializer;
		ALuint _source;
		ALuint _buffer;
	
	public:
		ALAudio(void);
		ALAudio(const void *data, ALenum format, ALsizei size, ALsizei freq);
		~ALAudio(void);
		void load(const void *data, ALenum format, ALsizei size, ALsizei freq);
		void play(ALboolean loop = false) const;
		bool playing(void) const;
		void pause(void) const { alSourcePause(_source); }
		void stop(void) const { alSourceStop(_source); }
		ALuint id(void) const { return _source; }
	};
}

#endif  // WATERY_AL_AUDIO_H
