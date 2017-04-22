//
// Created by Mike Smith on 2017/4/18.
//

#include "bitmap.h"

namespace watery
{
	void Bitmap::load(const Size &size, const unsigned char *data)
	{
		if (_data != nullptr)
		{
			delete _data;
		}
		
		_size = size;
		_data = new unsigned char[size.volume()];
		memcpy(_data, data, size.volume());
	}
	
	void Bitmap::load(const Size &size, const std::vector<unsigned char> &data)
	{
		if (_data != nullptr)
		{
			delete _data;
		}
		
		_size = size;
		_data = new unsigned char[data.size()];
		memcpy(_data, data.data(), data.size());
	}
	
	void Bitmap::free(void)
	{
		if (_data != nullptr)
		{
			delete _data;
			_data = nullptr;
			_size.set_size(0, 0, 0);
		}
	}
	
	Bitmap::~Bitmap(void)
	{
		if (_data != nullptr)
		{
			delete _data;
		}
	}
}
