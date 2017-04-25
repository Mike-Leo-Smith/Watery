#version 330 core

in vec2 texture_coord;
out vec4 color;

uniform sampler2D sampler;

void main()
{
	color = texture(sampler, texture_coord);
}
