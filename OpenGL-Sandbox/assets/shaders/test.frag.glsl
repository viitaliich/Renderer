#version 410 core

layout (location = 0) out vec4 color;

in vec2 vTexCoord;

uniform vec4 uColor;
uniform sampler2D uTexture;


void main()
{
	vec4 texColor = texture(uTexture, vTexCoord);
	//color = vec4(1.0, 0.0, 0.0, 1.0);
	//color = vec4(uColor);
	color = vec4(texColor);
}