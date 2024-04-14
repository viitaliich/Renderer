#pragma once

#include "glpch.h"

#include <GLCore.h>
#include <GLCoreUtils.h>

namespace GLCore::Utils {

	struct VBLayoutElement
	{
		unsigned int type;
		unsigned int count;
		unsigned int normalised;

		static unsigned int GetSizeOfType(unsigned int type)
		{
			switch (type)
			{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
			}
			ASSERT(false);
			return 0;
		}
	};

	class VertexBufferLayout
	{
	private:
		std::vector<VBLayoutElement> mElements;
		unsigned int mStride;

	public:
		VertexBufferLayout()
			: mStride(0) {}

		template<typename T>
		void Push(unsigned int count)
		{
			static_assert(false);
		}

		template<>
		void Push<float>(unsigned int count)
		{
			mElements.push_back({ GL_FLOAT, count, GL_FALSE });		// ??? false
			mStride += VBLayoutElement::GetSizeOfType(GL_FLOAT) * count;
		}

		template<>
		void Push<unsigned int>(unsigned int count)
		{
			mElements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
			mStride += VBLayoutElement::GetSizeOfType(GL_UNSIGNED_INT) * count;

		}

		template<>
		void Push<unsigned char>(unsigned int count)
		{
			mElements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
			mStride += VBLayoutElement::GetSizeOfType(GL_UNSIGNED_BYTE) * count;
		}

		inline const std::vector<VBLayoutElement> GetElements() const& { return mElements; }
		inline unsigned int GetStride() const { return mStride; }

	};
}