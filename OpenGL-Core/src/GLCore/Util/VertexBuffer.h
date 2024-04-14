#pragma once

namespace GLCore::Utils {

	class VertexBuffer
	{
	private:
		unsigned int mRendererID;

	public:
		VertexBuffer(const void* data, unsigned int size);
		~VertexBuffer();

		void Bind() const;
		void Unbind() const;
	};
}