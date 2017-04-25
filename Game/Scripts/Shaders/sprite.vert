#version 330 core

layout (location = 0) in vec2 coord;

out vec2 texture_coord;

uniform vec2 position;
uniform vec2 size;

uniform mat4 projection;
uniform mat4 view;

void main()
{
	gl_Position = projection * view * vec4(position.x + coord.x * size.x, position.y + coord.y * size.y, 0.0f, 1.0f);
	texture_coord = vec2(coord.x, 1 - coord.y);
}
