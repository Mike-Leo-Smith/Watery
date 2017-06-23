/// @file shader.h
/// @brief Header file for class Shader.
/// @author ZSK
/// @date April 25, 2017

#ifndef WATERY_SHADER_H
#define WATERY_SHADER_H

#include "component.h"
#include "../../Framework/Graphics/gl_shader.h"

namespace watery
{
	/// @brief Shader component for objects.
	/// @see Component
	/// @see Object
	class Shader : public Component
	{
	private:
		/// @brief Pointer to OpenGL shader resource.
		/// @see GLShader
		GLShader *_shader;
	
	public:
		/// @brief Construct from pointer to OpenGL shader resource.
		/// @see Object
		/// @see ComponentFactory
		/// @see GLShader
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		Shader(GLShader *shader = nullptr) : Component("shader"), _shader(shader) {}
		
		/// @brief Destructor.
		/// @see Object
		/// @see ComponentFactory
		/// @note This function should not be called manually. Use it via the interfaces of ComponentFactory or Object.
		virtual ~Shader(void) override {}
		
		/// @brief Bind to a pointer to OpenGL shader.
		/// @param shader Pointer to OpenGL shader.
		/// @see GLShader
		virtual void bind_shader(GLShader *shader) { _shader = shader; }
		
		/// @brief Get const pointer to OpenGL shader.
		/// @return Const pointer to OpenGL shader.
		/// @see GLShader
		virtual const GLShader *shader(void) const { return _shader; }
		
		/// @brief Get pointer to OpenGL shader.
		/// @return Pointer to OpenGL shader.
		virtual GLShader *shader(void) { return _shader; }
	};
};

#endif  // WATERY_SHADER_H
