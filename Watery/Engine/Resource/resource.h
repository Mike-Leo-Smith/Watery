//
// Created by Mike Smith on 2017/5/25.
//

#ifndef WATERY_RESOURCE_H
#define WATERY_RESOURCE_H

#include <string>

namespace watery
{
	// Adapter for low-level data.
	class Resource
	{
	private:
		std::string _type
	
	public:
		Resource(const std::string &type = "undefined") : _type(type) {}
	};
}

#endif  // WATERY_RESOURCE_H
