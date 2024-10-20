#include "VertexBuffer.hpp"
#include "OpenGL/VertexBuffer.hpp"

#include "ResourceManagement/ResourceManager.hpp"

namespace Graphics {
	VB_Handle VertexBuffer::Create()
	{
		// TODO: Make it choose! Not hardcoded!
		VertexBuffer* vb = new OpenGL::VertexBuffer();
		return Game::ResourceManager::CreateVB(vb);
	}

	void VertexBuffer::FillData(VB_Handle vb, void* data, size_t size)
	{
		Game::ResourceManager::GetVB(vb)->fillData(data, size);
	}
}
