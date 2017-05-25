//
// Created by Mike Smith on 2017/5/25.
//

#include "gl_texture_wrapper.h"
#include "../../Framework/ThirdParty/lodepng.h"

namespace watery
{
	GLTextureWrapper::GLTextureWrapper(const std::string &file_name) : ResourceWrapper("gl_texture"), _texture(nullptr)
	{
		constexpr int depth = 4;
		unsigned int width, height;
		std::vector<unsigned char> pixels;
		
		lodepng::decode(pixels, width, height, file_name);
		_texture = new GLTexture(pixels.data(), width, height, depth);
	}
}