#version 330 core

layout (location = 0) in vec3 vert_coord;
layout (location = 1) in vec3 vert_color;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 model;

out vec3 color;

void main()
{
	gl_Position = proj * view * model * vec4(vert_coord, 1.0);
	color = vert_color;
}
