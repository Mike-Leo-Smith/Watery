//
// Created by Mike Smith on 2017/5/5.
//

#ifndef WATERY_AL_INITIALIZER_H
#define WATERY_AL_INITIALIZER_H

namespace watery
{
	class ALInitializer
	{
	private:
		ALInitializer(void);
		ALInitializer(const ALInitializer &) = delete;
		ALInitializer(ALInitializer &&) = delete;
		ALInitializer &operator=(const ALInitializer &) = delete;
		~ALInitializer(void) {}
	
	public:
		static ALInitializer &instance(void);
	};
};

#endif  // WATERY_AL_INITIALIZER_H
