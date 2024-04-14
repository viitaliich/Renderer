#include "glpch.h"
#include "VertexBuffer.h"

#include <GLCore.h>
#include <GLCoreUtils.h>


VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	glGenBuffers(1, &mRendererID);	// 1 - number of buffers
	glBindBuffer(GL_ARRAY_BUFFER, mRendererID);	// first argument - what is the purpose of usage
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &mRendererID);
}

void VertexBuffer::Bind() const
{
	// buffer is generated, now we need to select it.
	glBindBuffer(GL_ARRAY_BUFFER, mRendererID);	// first argument - what is the purpose of usage
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);	// first argument - what is the purpose of usage
}
