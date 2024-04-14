#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace GLCore::Utils {

	class VertexArray
	{
	private:
		unsigned int mRendererID;
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(const VertexBuffer* vertexBuffer, const VertexBufferLayout& vbLayout);

		void Bind() const;
		void Unbind() const;
	};
}