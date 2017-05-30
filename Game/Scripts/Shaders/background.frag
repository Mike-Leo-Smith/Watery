#version 330 core

in vec2 texture_coord;
out vec4 color;

uniform sampler2D sampler;
uniform float pixel_size_x;
const float pixel_size_y = 0;

void main()
{
	color = texture(sampler, texture_coord);

	if (color.a < 0.01)
	{
		discard;
	}

    vec2 direction = vec2(1, 0);
    vec4 sum = vec4(0.0);

    sum += texture(sampler, vec2(texture_coord.x - 8.0 * pixel_size_x * direction.x, texture_coord.y - 8.0 * pixel_size_y * direction.y)) * 0.003799;
    sum += texture(sampler, vec2(texture_coord.x - 7.0 * pixel_size_x * direction.x, texture_coord.y - 7.0 * pixel_size_y * direction.y)) * 0.008741;
    sum += texture(sampler, vec2(texture_coord.x - 6.0 * pixel_size_x * direction.x, texture_coord.y - 6.0 * pixel_size_y * direction.y)) * 0.017997;
    sum += texture(sampler, vec2(texture_coord.x - 5.0 * pixel_size_x * direction.x, texture_coord.y - 5.0 * pixel_size_y * direction.y)) * 0.033159;
    sum += texture(sampler, vec2(texture_coord.x - 4.0 * pixel_size_x * direction.x, texture_coord.y - 4.0 * pixel_size_y * direction.y)) * 0.054670;
    sum += texture(sampler, vec2(texture_coord.x - 3.0 * pixel_size_x * direction.x, texture_coord.y - 3.0 * pixel_size_y * direction.y)) * 0.080657;
    sum += texture(sampler, vec2(texture_coord.x - 2.0 * pixel_size_x * direction.x, texture_coord.y - 2.0 * pixel_size_y * direction.y)) * 0.106483;
    sum += texture(sampler, vec2(texture_coord.x - 1.0 * pixel_size_x * direction.x, texture_coord.y - 1.0 * pixel_size_y * direction.y)) * 0.125794;
    sum += texture(sampler, vec2(texture_coord.x + 0.0 * pixel_size_x * direction.x, texture_coord.y + 0.0 * pixel_size_y * direction.y)) * 0.137401;
    sum += texture(sampler, vec2(texture_coord.x + 1.0 * pixel_size_x * direction.x, texture_coord.y + 1.0 * pixel_size_y * direction.y)) * 0.125794;
    sum += texture(sampler, vec2(texture_coord.x + 2.0 * pixel_size_x * direction.x, texture_coord.y + 2.0 * pixel_size_y * direction.y)) * 0.106483;
    sum += texture(sampler, vec2(texture_coord.x + 3.0 * pixel_size_x * direction.x, texture_coord.y + 3.0 * pixel_size_y * direction.y)) * 0.080657;
    sum += texture(sampler, vec2(texture_coord.x + 4.0 * pixel_size_y * direction.x, texture_coord.y + 4.0 * pixel_size_y * direction.y)) * 0.054670;
    sum += texture(sampler, vec2(texture_coord.x + 5.0 * pixel_size_x * direction.x, texture_coord.y + 5.0 * pixel_size_y * direction.y)) * 0.033159;
    sum += texture(sampler, vec2(texture_coord.x + 6.0 * pixel_size_x * direction.x, texture_coord.y + 6.0 * pixel_size_y * direction.y)) * 0.017997;
    sum += texture(sampler, vec2(texture_coord.x + 7.0 * pixel_size_x * direction.x, texture_coord.y + 7.0 * pixel_size_y * direction.y)) * 0.008741;
    sum += texture(sampler, vec2(texture_coord.x + 8.0 * pixel_size_x * direction.x, texture_coord.y + 8.0 * pixel_size_y * direction.y)) * 0.003799;

    color = sum * vec4(texture_coord.x, 1, 1 - texture_coord.x, 1);
}
