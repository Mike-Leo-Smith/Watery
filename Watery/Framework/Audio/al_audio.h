//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_AL_AUDIO_H
#define WATERY_AL_AUDIO_H

#include <OpenAL/al.h>

namespace watery
{
	class ALAudio
	{
	private:
		ALuint _source;
		ALuint _buffer;
	
	public:
		ALAudio(void);
		ALAudio(const void *data, ALenum format, ALsizei size, ALsizei freq);
		virtual ~ALAudio(void);
		virtual void load(const void *data, ALenum format, ALsizei size, ALsizei freq);
		virtual void play(ALboolean loop = true) const;
		virtual void pause(void) const { alSourcePause(_source); }
		virtual void stop(void) const { alSourceStop(_source); }
		virtual ALuint id(void) const { return _source; }
	};
}

#endif  // WATERY_AL_AUDIO_H
