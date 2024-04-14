#pragma once

namespace GLCore::Utils {

	class IndexBuffer
	{
	private:
		unsigned int mRendererID;
		unsigned int mCount;

	public:
		IndexBuffer(const unsigned int* data, unsigned int count);
		~IndexBuffer();

		void Bind() const;
		void Unbind() const;

		inline void SetCount(unsigned int count) { mCount = count; };
		inline unsigned int GetCount() const { return mCount; };
	};
}