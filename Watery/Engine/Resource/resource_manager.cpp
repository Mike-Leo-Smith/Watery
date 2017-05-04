//
// Created by Mike Smith on 2017/4/17.
//

#include <AL/alut.h>
#include "resource_manager.h"
#include "../../Framework/Image/lodepng.h"

watery::GLTexture *watery::Resource::load_texture(const std::string &file_name) const
{
	constexpr int depth = 4;
	unsigned int width, height;
	std::vector<unsigned char> pixels;
	
	lodepng::decode(pixels, width, height, file_name);
	
	return new GLTexture(pixels.data(), width, height, depth);
}

watery::ALAudio *watery::Resource::load_audio(const std::string &file_name) const
{
	ALenum format;
	ALsizei size;
	ALsizei freq;
	ALvoid *data;
	ALAudio *audio;
	
	// alutCreateBufferFromFile dose not work properly here, do we have to use the deprecated methods.
	alutLoadWAVFile((ALbyte *)file_name.c_str(), &format, &data, &size, &freq);
	audio = new ALAudio(data, format, size, freq);
	alutUnloadWAV(format, data, size, freq);
	
	return audio;
}
