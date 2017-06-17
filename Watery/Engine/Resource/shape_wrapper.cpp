//
// Created by Mike Smith on 2017/5/26.
//

#include <fstream>
#include "shape_wrapper.h"
#include "../../Framework/Physics/circle.h"
#include "../../Framework/Physics/rectangle.h"

namespace watery
{
	ShapeWrapper::ShapeWrapper(const std::string &file_name) : ResourceWrapper("shape"), _shape(nullptr)
	{
		std::ifstream file(file_name);
		
		if (file.is_open())
		{
			std::string type;
			
			file >> type;
			if (type == "circle")
			{
				std::string radius_tag, offset_tag;
				float radius, center_x, center_y;
				
				file >> radius_tag >> radius;
				file >> offset_tag >> center_x >> center_y;
				
				_shape = new Circle(center_x, center_y, radius);
			}
			else if (type == "rectangle")
			{
				std::string left_bottom_tag, right_top_tag;
				float left, bottom, right, top;
				
				file >> left_bottom_tag >> left >> bottom;
				file >> right_top_tag >> right >> top;
				
				_shape = new Rectangle(left, bottom, right, top);
			}
		}
	}
}