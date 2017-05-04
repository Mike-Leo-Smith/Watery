//
// Created by Mike Smith on 2017/4/17.
//

#ifndef WATERY_RESOURCE_MANAGER_H
#define WATERY_RESOURCE_MANAGER_H

#include "../System/system.h"
#include "../../Framework/Audio/al_audio.h"
#include "../../Framework/Graphics/gl_texture.h"

namespace watery
{
	class Resource
	{
	public:
		virtual GLTexture *load_texture(const std::string &file_name) const;
		virtual ALAudio *load_audio(const std::string &file_name) const;
	};
}

#endif  // WATERY_RESOURCE_MANAGER_H
