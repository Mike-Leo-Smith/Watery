//
// Created by Mike Smith on 2017/4/25.
//

#ifndef WATERY_SHADER_H
#define WATERY_SHADER_H

#include "../../Framework/Graphics/gl_shader.h"
#include "component.h"

namespace watery
{
	class Shader : public Component
	{
	private:
		const GLShader *_shader;
	
	public:
		Shader(const GLShader *shader = nullptr) : Component(COMPONENT_SHADER), _shader(shader) {}
		virtual ~Shader(void) {}
		virtual void bind_shader(const GLShader *shader) { _shader = shader; }
		virtual const GLShader *shader(void) const { return _shader; }
	};
};

#endif  // WATERY_SHADER_H
