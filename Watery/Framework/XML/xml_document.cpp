//
// Created by Mike Smith on 2017/5/13.
//

#include <stack>
#include <sstream>
#include <fstream>
#include "xml_document.h"

namespace watery
{
	XMLDocument::~XMLDocument(void)
	{
		if (_root != nullptr)
		{
			delete _root;   // Sub elements will be deleted recursively.
		}
	}
	
	void XMLDocument::load(const std::string &file_name)
	{
		std::ifstream file(file_name);
		std::stack<XMLElement *> element_stack;
		
		if (file.is_open())
		{
			while (!file.eof())
			{
				int c = file.get();
				
				if (c == '<')           // Reading a tag
				{
					c = file.get();     // Read the next character and determine what to do.
					
					if (c == '/')       // A closing tag.
					{
						std::stringstream buffer;
						std::string close_tag;
						
						// Read the tag.
						while ((c = file.get()) != '>')
						{
							buffer << (char)c;
						}
						buffer >> close_tag;
						
						// Test if the tag is closed correctly.
						if (element_stack.empty() || element_stack.top()->tag() != close_tag)
						{
							delete _root;
							_root = nullptr;
							return;
						}
						
						// Close the tag.
						element_stack.pop();
					}
					else if (c == '!')  // Comments.
					{
						while (c != '>')
						{
							c = file.get();
						}
					}
					else                // An open tag.
					{
						std::string buffer;
						
						// Skip blank characters.
						while (isblank(c))
						{
							c = file.get();
						}
						
						// Read the tag.
						while (c != '>')
						{
							buffer.push_back((char)c);
							c = file.get();
						}
						buffer.push_back('>');
						// Clear leading and tailing blanks.
						/*while (isblank(buffer.back()))
						{
							buffer.pop_back();
						}*/
						
						int index = 0;
						std::string tag_name;
						
						// Get the name of the tag.
						while (!isblank(buffer[index]) && buffer[index] != '>')
						{
							tag_name.push_back(buffer[index++]);
						}
						
						XMLElement *element;
						
						// Create a subelement.
						if (element_stack.empty())
						{
							element = _root = new XMLElement(tag_name);
						}
						else
						{
							element = element_stack.top()->create_child(tag_name);
						}
						
						while (true)
						{
							while (isblank(buffer[index])) { index++; }
							if (buffer[index] == '/')
							{
								break;//Need not to be put in the stack.
							}
							else if (buffer[index] == '>')
							{
								element_stack.push(element);//Put in the stack.
								break;
							}
							std::string attrib_name = "";
							std::string attrib_val = "";
							
							// Skip blanks.
							while (isblank(buffer[index])) { index++; }
							
							// Read attributes.
							while (buffer[index] != '=')
							{
								attrib_name.push_back(buffer[index++]);
							}
							
							index += 2;   // Skip the following quotation mark.
							// Read the value of the attribute.
							while (buffer[index] != '\"')
							{
								attrib_val.push_back(buffer[index++]);
							}
							
							element->set_attribute(attrib_name, attrib_val);
							index++;
						}
					}
				}
			}
		}
	}
}

int test(void)
{
	watery::XMLDocument xml;
	xml.load("demo.xml");
	xml.print(-4);
	return 0;
}