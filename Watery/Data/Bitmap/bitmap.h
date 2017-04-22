//
// Created by Mike Smith on 2017/4/18.
//

#ifndef WATERY_BITMAP_H
#define WATERY_BITMAP_H

#include <vector>
#include "../Size/size.h"

namespace watery
{
	class Bitmap
	{
	private:
		Size _size;
		unsigned char *_data;
	
	public:
		Bitmap(void) : _data(nullptr) {}
		virtual ~Bitmap(void);
		virtual const unsigned char *data(void) const { return _data; }
		virtual const Size &size(void) const { return _size; }
		virtual bool empty(void) const { return (_data == nullptr); }
		virtual void load(const Size &size, const unsigned char *data);
		virtual void load(const Size &size, const std::vector<unsigned char> &data);
		virtual void free(void);
	};
}

#endif  // WATERY_BITMAP_H
