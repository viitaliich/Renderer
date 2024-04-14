#include "glpch.h"
#include "Renderer.h"

//using namespace GLCore;
//using namespace GLCore::Utils;

namespace GLCore::Render
{
	void Renderer::Draw(const GLCore::Utils::VertexArray* vertexArray,
		const GLCore::Utils::IndexBuffer* indexBuffer,
		const GLCore::Utils::Shader* shader) const
	{
		shader->Bind();
		vertexArray->Bind();
		indexBuffer->Bind();

		glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Renderer::Clear(float r, float g, float b, float a) const
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}