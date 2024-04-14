#pragma once

#include <GLCore.h>
#include <GLCoreUtils.h>

namespace GLCore::Render
{
	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

		void Draw(const GLCore::Utils::VertexArray* vertexArray, 
			const GLCore::Utils::IndexBuffer* indexBuffer, 
			const GLCore::Utils::Shader* shader) const;
		
		void Clear(float r, float g, float b, float a) const;

	};
}