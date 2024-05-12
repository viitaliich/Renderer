#version 410 core

layout (location = 0) in vec4 aPosition;
layout (location = 1) in vec2 aTexCoord;

out vec2 vTexCoord;

uniform mat4 uMVP;

void main()
{
	gl_Position = uMVP * aPosition;
	vTexCoord = aTexCoord;
}