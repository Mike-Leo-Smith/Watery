/// @file audio.h
/// @brief Header file for class Audio.
/// @author YJY
/// @date May 7, 2017

#ifndef WATERY_AUDIO_H
#define WATERY_AUDIO_H

#ifndef _WIN32

#include "../../Framework/Audio/al_audio.h"
#include "component.h"

namespace watery
{
	/// @brief Audio component for objects.
	/// @note Disabled on Windows due to incompatibility.
	/// @see Component
	/// @see Object
	class Audio : public Component
	{
	private:
		/// @brief Pointer to OpenAL audio resources.
		/// @see ALAudio
		ALAudio *_audio;
	
	public:
		/// @brief Construct from ALAudio pointers.
		/// @param audio Pointer to OpenAL audio resources.
		/// @see Component
		/// @see ALAudio
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		Audio(ALAudio *audio = nullptr) : Component("audio"), _audio(audio) {}
		
		/// @brief Destructor.
		/// @see ComponentFactory
		/// @see Object
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual ~Audio(void) override {}
		
		/// @brief Bind an ALAudio pointer to the component.
		/// @param audio AlAudio pointer to bind.
		/// @see ALAudio
		virtual void bind_audio(ALAudio *audio) { _audio = audio; }
		
		/// @brief Get the const pointer to the bound ALAudio resource.
		/// @return Const pointer to the bound ALAudio resource.
		virtual const ALAudio *audio(void) const { return _audio; }
		
		/// @brief Get the pointer to the bound ALAudio resource.
		/// @return Pointer to the bound ALAudio resource.
		virtual ALAudio *audio(void) { return _audio; }
	};
}

#endif

#endif  // WATERY_AUDIO_H
