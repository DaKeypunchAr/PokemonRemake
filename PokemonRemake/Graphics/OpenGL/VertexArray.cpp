#include "VertexArray.hpp"
#include "glad/glad.h"
#include "Logger/Logger.hpp"

namespace OpenGL
{
	VertexArray::VertexArray()
		: Graphics::VertexArray(), m_API_ID(0)
	{
		glCreateVertexArrays(1, &m_API_ID);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_API_ID);
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(m_API_ID);
	}

	void VertexArray::linkBuffer(const Graphics::VertexBuffer* vBuffer, const std::vector<Graphics::Attribute>& attributes) const
	{
		unsigned int vb;
		vBuffer->getAPI_ID(&vb);

		static auto getGLType = [&](Graphics::ShaderDataType type)
		{
			switch (type)
			{
			case Graphics::ShaderDataType::FLOAT:
			case Graphics::ShaderDataType::FLOAT2:
			case Graphics::ShaderDataType::FLOAT3:
			case Graphics::ShaderDataType::FLOAT4:
				return GL_FLOAT;
			default:
				return 0;
			}
		};

		int stride = 0;
		for (unsigned int i = 0; i < attributes.size(); i++)
		{
			glVertexArrayAttribFormat(m_API_ID, i, GetShaderDataTypeCount(attributes[i].type), getGLType(attributes[i].type), attributes[i].normalized, stride);
			glVertexArrayAttribBinding(m_API_ID, i, 0);
			glEnableVertexArrayAttrib(m_API_ID, i);
			stride += GetShaderDataTypeSize(attributes[i].type);
		}

		glVertexArrayVertexBuffer(m_API_ID, 0, vb, 0, stride);

	}

	void VertexArray::linkBuffer(const Graphics::VertexBuffer* vb, const std::initializer_list<Graphics::Attribute>& attributes) const
	{
		linkBuffer(vb, std::vector(attributes));
	}


	void VertexArray::getAPI_ID(void* id)
	{
		*static_cast<unsigned int*>(id) = m_API_ID;
	}

}
