//
// Created by Mike Smith on 2017/5/25.
//

#ifndef WATERY_GL_SHADER_WRAPPER_H
#define WATERY_GL_SHADER_WRAPPER_H

#include "resource_wrapper.h"
#include "../../Framework/Graphics/gl_shader.h"

namespace watery
{
	class GLShaderWrapper : public ResourceWrapper
	{
	private:
		GLShader *_shader;
	
	public:
		GLShaderWrapper(const std::string &file_name);
		virtual ~GLShaderWrapper(void) override { delete _shader; }
		virtual void *data(void) override { return _shader; }
	};
}

#endif  // WATERY_GL_SHADER_WRAPPER_H
