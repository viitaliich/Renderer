#include "glpch.h"
#include "IndexBuffer.h"

#include <GLCore.h>
#include <GLCoreUtils.h>

namespace GLCore::Utils {

	IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
		: mCount(count)
	{
		glGenBuffers(1, &mRendererID);	// 1 - number of buffers
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);	// first argument - what is the purpose of usage
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
	}

	IndexBuffer::~IndexBuffer()
	{
		glDeleteBuffers(1, &mRendererID);
	}

	void IndexBuffer::Bind() const
	{
		// buffer is generated, now we need to select it.
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);	// first argument - what is the purpose of usage
	}

	void IndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);	// first argument - what is the purpose of usage
	}
}