//
// Created by Mike Smith on 2017/5/13.
//

#ifndef WATERY_XML_DOCUMENT_H
#define WATERY_XML_DOCUMENT_H

#include "xml_element.h"

namespace watery
{
	class XMLDocument
	{
	private:
		XMLElement *_root;
	
	public:
		XMLDocument(void) : _root(nullptr) {}
		XMLDocument(const std::string &file_name) : _root(nullptr) { load(file_name); }
		~XMLDocument(void);
		void load(const std::string &file_name);
		XMLElement *root(void) { return _root; }
		const XMLElement *root(void) const { return _root; }
		bool empty(void) const { return (_root == nullptr); }
	};
}

#endif  // WATERY_XML_DOCUMENT_H
