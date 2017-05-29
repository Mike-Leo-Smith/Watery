//
// Created by Mike Smith on 2017/5/17.
//

#ifndef WATERY_TEXT_H
#define WATERY_TEXT_H

#include <string>
#include "component.h"
#include "../Mathematics/vector.h"

namespace watery
{
	class Text : public Component
	{
	private:
		std::string _content;
		std::string _font;
		float _size;
		Vector _position;
	
	public:
		Text(const std::string &content) : Component("text") {}
		virtual ~Text(void) override {}
		virtual const std::string &content(void) const { return _content; }
		virtual const std::string &font(void) const { return _font; }
		virtual float size(void) const { return _size; }
		virtual const Vector &position(void) const { return _position; }
		virtual void set_content(const std::string &content) { _content = content; }
		virtual void set_font(const std::string &font) { _font = font; }
		virtual void set_size(float size) { _size = size; }
		virtual void set_position(const Vector &position) { _position = position; }
	};
}

#endif  // WATERY_TEXT_H
