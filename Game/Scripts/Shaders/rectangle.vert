#version 330 core

layout (location = 0) in vec3 coord;

uniform float x1;
uniform float y1;
uniform float x2;
uniform float y2;

uniform mat4 proj;
uniform mat4 mat;

void main()
{
	float x_scale = x2 - x1;
	float y_scale = y2 - y1;

	gl_Position = proj * mat * vec4(coord.x * x_scale + x1, coord.y * y_scale + y1, coord.z, 1.0);
}
