//
// Created by Mike Smith on 2017/4/19.
//

#ifndef WATERY_COLOR_H
#define WATERY_COLOR_H

#include <cstring>

namespace watery
{
	class Color
	{
	private:
		float _rgba[4];
		
	public:
		Color(float red = 0, float green = 0, float blue = 0, float alpha = 0) : _rgba{red, green, blue, alpha} {}
		Color(const float *rgba) { memmove(_rgba, rgba, 4); }
		~Color(void) {}
		float red(void) const { return _rgba[0]; }
		float green(void) const { return _rgba[1]; }
		float blue(void) { return _rgba[2]; }
		float alpha(void) { return _rgba[3]; }
		const float *rgba(void) const { return _rgba; }
		void set_red(float red) { _rgba[0] = red; }
		void set_green(float green) { _rgba[1] = green; }
		void set_blue(float blue) { _rgba[2] = blue; }
		void set_alpha(float alpha) { _rgba[3] = alpha; }
		void set_rgba(const float *rgba) { memmove(_rgba, rgba, 4); }
	};
}

#endif  // WATERY_COLOR_H
