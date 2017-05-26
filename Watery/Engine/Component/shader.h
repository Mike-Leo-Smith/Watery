//
// Created by Mike Smith on 2017/4/25.
//

#ifndef WATERY_SHADER_H
#define WATERY_SHADER_H

#include "component.h"
#include "../../Framework/Graphics/gl_shader.h"

namespace watery
{
	class Shader : public Component
	{
	private:
		GLShader *_shader;
	
	public:
		Shader(GLShader *shader = nullptr) : Component("shader"), _shader(shader) {}
		virtual ~Shader(void) override {}
		virtual void bind_shader(GLShader *shader) { _shader = shader; }
		virtual const GLShader *shader(void) const { return _shader; }
		virtual GLShader *shader(void) { return _shader; }
	};
};

#endif  // WATERY_SHADER_H
