//
// Created by Mike Smith on 2017/5/25.
//

#ifndef WATERY_RESOURCE_WRAPPER_H
#define WATERY_RESOURCE_WRAPPER_H

#include <string>

namespace watery
{
	// Adapter for low-level data.
	class ResourceWrapper
	{
	private:
		std::string _type;
	
	public:
		ResourceWrapper(const std::string &type = "undefined") : _type(type) {}
		virtual ~ResourceWrapper(void) {}
		virtual const std::string &type(void) const { return _type; }
		virtual void *data(void) = 0;
	};
}

#endif  // WATERY_RESOURCE_WRAPPER_H
