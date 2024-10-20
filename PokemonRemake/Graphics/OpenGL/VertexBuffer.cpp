#include "VertexBuffer.hpp"

#include <glad/glad.h>

namespace OpenGL {
	VertexBuffer::VertexBuffer()
		: Graphics::VertexBuffer(), m_API_ID(0)
	{
		glCreateBuffers(1, &m_API_ID);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_API_ID);
	}

	void VertexBuffer::fillData(void* data, unsigned long size)
	{
		glNamedBufferData(m_API_ID, size, data, GL_STATIC_DRAW);
	}

	void VertexBuffer::getAPI_ID(void* apiId) const
	{
		*static_cast<unsigned int*>(apiId) = m_API_ID;
	}

}
