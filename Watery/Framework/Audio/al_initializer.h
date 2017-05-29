//
// Created by Mike Smith on 2017/5/5.
//

#ifndef WATERY_AL_INITIALIZER_H
#define WATERY_AL_INITIALIZER_H

#ifndef _WIN32

namespace watery
{
	class ALInitializer
	{
	private:
		static ALInitializer *_instance;
		ALInitializer(void);
		ALInitializer(const ALInitializer &) = delete;
		ALInitializer(ALInitializer &&) = delete;
		ALInitializer &operator=(const ALInitializer &) = delete;
		~ALInitializer(void) {}
	};
};

#endif

#endif  // WATERY_AL_INITIALIZER_H
