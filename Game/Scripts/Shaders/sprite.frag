#version 330 core

in vec2 texture_coord;
out vec4 color;

uniform sampler2D sampler;
uniform float pixelsizex;

void main()
{
	color = texture(sampler, texture_coord);

	if (color.a < 0.01)
	{
		discard;
	}

    vec2 direction = vec2(1, 0);

    vec4 sum = vec4(0.0);
    float pixelsizey = 0;

    sum += texture(sampler, vec2(texture_coord.x - 8.0 * pixelsizex * direction.x, texture_coord.y - 8.0 * pixelsizey * direction.y)) * 0.003799;
    sum += texture(sampler, vec2(texture_coord.x - 7.0 * pixelsizex * direction.x, texture_coord.y - 7.0 * pixelsizey * direction.y)) * 0.008741;
    sum += texture(sampler, vec2(texture_coord.x - 6.0 * pixelsizex * direction.x, texture_coord.y - 6.0 * pixelsizey * direction.y)) * 0.017997;
    sum += texture(sampler, vec2(texture_coord.x - 5.0 * pixelsizex * direction.x, texture_coord.y - 5.0 * pixelsizey * direction.y)) * 0.033159;
    sum += texture(sampler, vec2(texture_coord.x - 4.0 * pixelsizex * direction.x, texture_coord.y - 4.0 * pixelsizey * direction.y)) * 0.054670;
    sum += texture(sampler, vec2(texture_coord.x - 3.0 * pixelsizex * direction.x, texture_coord.y - 3.0 * pixelsizey * direction.y)) * 0.080657;
    sum += texture(sampler, vec2(texture_coord.x - 2.0 * pixelsizex * direction.x, texture_coord.y - 2.0 * pixelsizey * direction.y)) * 0.106483;
    sum += texture(sampler, vec2(texture_coord.x - 1.0 * pixelsizex * direction.x, texture_coord.y - 1.0 * pixelsizey * direction.y)) * 0.125794;
    sum += texture(sampler, vec2(texture_coord.x + 0.0 * pixelsizex * direction.x, texture_coord.y + 0.0 * pixelsizey * direction.y)) * 0.137401;
    sum += texture(sampler, vec2(texture_coord.x + 1.0 * pixelsizex * direction.x, texture_coord.y + 1.0 * pixelsizey * direction.y)) * 0.125794;
    sum += texture(sampler, vec2(texture_coord.x + 2.0 * pixelsizex * direction.x, texture_coord.y + 2.0 * pixelsizey * direction.y)) * 0.106483;
    sum += texture(sampler, vec2(texture_coord.x + 3.0 * pixelsizex * direction.x, texture_coord.y + 3.0 * pixelsizey * direction.y)) * 0.080657;
    sum += texture(sampler, vec2(texture_coord.x + 4.0 * pixelsizey * direction.x, texture_coord.y + 4.0 * pixelsizey * direction.y)) * 0.054670;
    sum += texture(sampler, vec2(texture_coord.x + 5.0 * pixelsizex * direction.x, texture_coord.y + 5.0 * pixelsizey * direction.y)) * 0.033159;
    sum += texture(sampler, vec2(texture_coord.x + 6.0 * pixelsizex * direction.x, texture_coord.y + 6.0 * pixelsizey * direction.y)) * 0.017997;
    sum += texture(sampler, vec2(texture_coord.x + 7.0 * pixelsizex * direction.x, texture_coord.y + 7.0 * pixelsizey * direction.y)) * 0.008741;
    sum += texture(sampler, vec2(texture_coord.x + 8.0 * pixelsizex * direction.x, texture_coord.y + 8.0 * pixelsizey * direction.y)) * 0.003799;

    color = sum;
}
