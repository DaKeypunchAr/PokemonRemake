#include "VertexBuffer.hpp"
#include "OpenGL/VertexBuffer.hpp"

#include "RenderCommand.hpp"
#include "Logger/Logger.hpp"
#include "ResourceManagement/ResourceManager.hpp"

namespace Graphics {
	VB_Handle VertexBuffer::Create()
	{
		VertexBuffer* vb;
		switch (RenderCommand::GetAPI())
		{
		case API::OPENGL:
			vb = new OpenGL::VertexBuffer();
			return Game::ResourceManager::CreateVB(vb);
		case API::NONE: Logger::Log("[VertexBuffer::Create]: None API received!", Logger::Severity::ERR);
		default:        Logger::Log("[VertexBuffer::Create]: Unknown API received", Logger::Severity::ERR);
		}
	}

	void VertexBuffer::FillData(VB_Handle vb, void* data, size_t size)
	{
		Game::ResourceManager::GetVB(vb)->fillData(data, size);
	}
}
