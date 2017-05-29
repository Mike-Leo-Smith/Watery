//
// Created by Mike Smith on 2017/5/26.
//

#ifndef WATERY_SHAPE_WRAPPER_H
#define WATERY_SHAPE_WRAPPER_H

#include "../Physics/shape.h"
#include "resource_wrapper.h"

namespace watery
{
	class ShapeWrapper : public ResourceWrapper
	{
	private:
		Shape *_shape;
	
	public:
		ShapeWrapper(const std::string &file_name);
		virtual ~ShapeWrapper(void) override { delete _shape; }
		virtual void *data(void) override { return _shape; }
	};
}

#endif  // WATERY_SHAPE_WRAPPER_H
