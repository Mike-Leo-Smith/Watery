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
		~XMLDocument(void);
		void load(const std::string &file_name);
		XMLElement *root(void) { return _root; }
		const XMLElement *root(void) const { return _root; }
		void print(int depth) { _root->print(depth); };
	};
}

#endif  // WATERY_XML_DOCUMENT_H
