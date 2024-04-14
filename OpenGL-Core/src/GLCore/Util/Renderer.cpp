#include "glpch.h"
#include "Renderer.h"



void Renderer::Draw(const VertexArray* vertexArray, const IndexBuffer* indexBuffer, const GLCore::Utils::Shader* shader) const
{
	shader->Bind();
	vertexArray->Bind();
	indexBuffer->Bind();

	glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Clear(float r, float g, float b, float a) const
{
	//glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
