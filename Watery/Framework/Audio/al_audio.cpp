//
// Created by Mike Smith on 2017/4/17.
//

#include <al/alut.h>
#include "al_audio.h"

namespace watery
{
	ALAudio::ALAudio(void)
	{
		alGenBuffers(1, &_buffer);
		alGenSources(1, &_source);
	}
	
	ALAudio::ALAudio(const void *data, ALenum format, ALsizei size, ALsizei freq)
	{
		alGenBuffers(1, &_buffer);
		alGenSources(1, &_source);
		load(data, format, size, freq);
	}
	
	ALAudio::~ALAudio(void)
	{
		alDeleteBuffers(1, &_buffer);
		alDeleteSources(1, &_source);
	}
	
	void ALAudio::load(const void *data, ALenum format, ALsizei size, ALsizei freq)
	{
		alBufferData(_buffer, format, data, size, freq);
		alSourcei(_source, AL_BUFFER, _buffer);
	}
	
	void ALAudio::play(ALboolean loop) const
	{
		alSourcef(_source, AL_PITCH, 2);
		alSourcei(_source, AL_LOOPING, loop);
		alSourcePlay(_source);
	}
	
	bool ALAudio::playing(void) const
	{
		ALint state;
		
		alGetSourcei(_source, AL_SOURCE_STATE, &state);
		return (state == AL_PLAYING);
	}
}