#include "glpch.h"
#include "VertexArray.h"

namespace GLCore::Utils {

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &mRendererID);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &mRendererID);
	}

	void VertexArray::AddBuffer(const VertexBuffer* vertexBuffer, const VertexBufferLayout& vbLayout)
	{
		Bind();
		vertexBuffer->Bind();
		const auto& elements = vbLayout.GetElements();
		unsigned int offset = 0;

		for (unsigned int i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			glEnableVertexAttribArray(i);	// ??? 0
			glVertexAttribPointer(i, element.count, element.type,
				element.normalised, vbLayout.GetStride(), (const void*)offset);
			offset += element.count * VBLayoutElement::GetSizeOfType(element.type);

		}
	}

	void VertexArray::Bind() const
	{
		glBindVertexArray(mRendererID);
	}

	void VertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
}