#version 410 core

layout (location = 0) out vec4 color;

uniform vec4 uColor;

void main()
{
	//color = vec4(1.0, 0.0, 0.0, 1.0);
	color = vec4(uColor);
}