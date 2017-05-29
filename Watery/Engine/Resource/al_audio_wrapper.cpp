//
// Created by Mike Smith on 2017/5/25.
//

#ifndef _WIN32

#include <al/alut.h>
#include "al_audio_wrapper.h"

namespace watery
{
	ALAudioWrapper::ALAudioWrapper(const std::string &file_name) : ResourceWrapper("al_audio"), _audio(nullptr)
	{
		ALenum format;
		ALsizei size;
		ALsizei freq;
		ALvoid *data;
		
		// Function alutCreateBufferFromFile() dose not work properly here, do we have to use the deprecated methods.
		alutLoadWAVFile((ALbyte *)file_name.c_str(), &format, &data, &size, &freq);
		_audio = new ALAudio(data, format, size, freq);
		alutUnloadWAV(format, data, size, freq);
	}
}

#endif