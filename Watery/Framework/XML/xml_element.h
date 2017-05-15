//
// Created by Mike Smith on 2017/5/13.
//

#ifndef WATERY_XML_ELEMENT_H
#define WATERY_XML_ELEMENT_H

#include <string>
#include <vector>
#include <map>

#include <iostream>

namespace watery
{
	class XMLElement
	{
	private:
		std::string _tag;
		std::string _text;
		std::map<std::string, std::string> _attributes;
		std::map<std::string, std::vector<XMLElement *>> _children;
	
	public:
		XMLElement(const std::string &tag = "");
		~XMLElement(void);
		const std::string &tag(void) const { return _tag; }
		const std::string &text(void) const { return _text; }
		const std::string &attribute(const std::string &name) const;
		const std::vector<XMLElement *> &child(const std::string &sub_tag) const;
		void set_tag(const std::string &tag) { _tag = tag; }
		void set_text(const std::string &text) { _text = text; }
		void set_attribute(const std::string &name, const std::string &value);
		XMLElement *create_child(const std::string &child_tag);
		
		void print(int depth);
	};
}

#endif  // WATERY_XML_ELEMENT_H
