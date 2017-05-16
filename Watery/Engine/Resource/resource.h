//
// Created by Mike Smith on 2017/5/16.
//

#ifndef WATERY_RESOURCE_H
#define WATERY_RESOURCE_H

#include <string>

namespace watery
{
	class Resource
	{
	private:
		std::string _type;
		virtual void *get_data(void) = 0;
	
	public:
		template<typename DATA_TYPE> DATA_TYPE data(void) { return static_cast<DATA_TYPE>(get_data()); }
	};
}

#endif  // WATERY_RESOURCE_H
