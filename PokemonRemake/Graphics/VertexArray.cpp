#include "VertexArray.hpp"
#include "OpenGL/VertexArray.hpp"

#include "ResourceManagement/ResourceManager.hpp"

namespace Graphics
{
	VA_Handle VertexArray::Create()
	{
		// TODO: Make it choose! Not hardcoded!
		VertexArray* va = new OpenGL::VertexArray();
		return Game::ResourceManager::CreateVA(va);
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
