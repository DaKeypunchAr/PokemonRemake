#include "VertexArray.hpp"
#include "OpenGL/VertexArray.hpp"

#include "RenderCommand.hpp"
#include "Logger/Logger.hpp"
#include "ResourceManagement/ResourceManager.hpp"

namespace Graphics
{
	VA_Handle VertexArray::Create()
	{
		VertexArray* va = nullptr;
		switch (RenderCommand::GetAPI())
		{
		case API::OPENGL:
			 va = new OpenGL::VertexArray();
			return Game::ResourceManager::CreateVA(va);
		case API::NONE: Logger::Log("[VertexArray::Create]: None API received!", Logger::Severity::ERR);
		default:        Logger::Log("[VertexArray::Create]: Unknown API received", Logger::Severity::ERR);
		}
	}

	void VertexArray::Bind(VA_Handle va)
	{
		Game::ResourceManager::GetVA(va)->bind();
	}

	void VertexArray::LinkBuffer(VA_Handle va, VB_Handle vb, const std::vector<Attribute>& attribs)
	{
		Game::ResourceManager::GetVA(va)->linkBuffer(Game::ResourceManager::GetVB(vb), attribs);
	}

	void VertexArray::LinkBuffer(VA_Handle va, VB_Handle vb, const std::initializer_list<Attribute>& attribs)
	{
		Game::ResourceManager::GetVA(va)->linkBuffer(Game::ResourceManager::GetVB(vb), attribs);
	}
}
