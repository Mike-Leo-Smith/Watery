//
// Created by Mike Smith on 2017/5/13.
//

#include "xml_element.h"

namespace watery
{
	XMLElement::XMLElement(const std::string &tag) : _tag(tag)
	{
		_attributes.emplace("", "");
		_children.emplace("", std::vector<XMLElement *>());
	}
	
	XMLElement::~XMLElement(void)
	{
		for (auto &item : _children)
		{
			for (auto &child : item.second)
			{
				delete child;
			}
		}
	}
	
	const std::string &XMLElement::attribute(const std::string &name) const
	{
		return _attributes.count(name) ? _attributes.at(name) : _attributes.at("");
	}
	
	const std::vector<XMLElement *> &XMLElement::child(const std::string &sub_tag) const
	{
		return _children.count(sub_tag) ? _children.at(sub_tag) : _children.at("");
	}
	
	void XMLElement::set_attribute(const std::string &name, const std::string &value)
	{
		_attributes.emplace(name, value);
	}
	
	XMLElement *XMLElement::create_child(const std::string &child_tag)
	{
		XMLElement *element = new XMLElement(child_tag);
		
		if (_children.count(child_tag) == 0)
		{
			_children.emplace(child_tag, std::vector<XMLElement *>());
		}
		_children.at(child_tag).push_back(element);
		
		return element;
	}
	
	void XMLElement::print(int depth)
	{
		for (int i = 0; i < depth; i++)std::cout << ' ';
		std::cout << _tag;
		std::cout << " ";
		for (auto &item : _attributes)if (item.first != "")std::cout << item.first << "=" << item.second << ' ';
		std::cout << std::endl;
		for (auto &item : _children)
		{
			for (auto &child : item.second)
			{
				child->print(depth + 4);
			}
		}
	}
}