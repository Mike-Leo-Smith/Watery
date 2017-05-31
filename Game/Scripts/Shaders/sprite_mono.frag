#version 330 core

in vec2 texture_coord;
out vec4 color;

uniform sampler2D sampler;

void main()
{
	color = texture(sampler, texture_coord);

	if (color.a < 0.01)
	{
		discard;
	}

	float avg = (color.r + color.g + color.b) / 3;
	color = vec4(avg, avg, avg, color.a);
}
