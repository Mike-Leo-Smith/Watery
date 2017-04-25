#version 330 core

out vec4 color;
uniform vec3 rgb;

void main()
{
	color = vec4(rgb, 1.0f);
}
