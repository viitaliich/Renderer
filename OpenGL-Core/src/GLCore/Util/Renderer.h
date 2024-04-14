#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>

class Renderer
{
public:
	Renderer() = default;
	~Renderer() = default;

	
	void Draw(const VertexArray* vertexArray, const IndexBuffer* indexBuffer, const GLCore::Utils::Shader* shader) const;
	void Clear(float r, float g, float b, float a) const;

};