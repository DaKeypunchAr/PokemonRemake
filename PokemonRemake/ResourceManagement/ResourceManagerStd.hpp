#pragma once
#include "ResourceManager.hpp"

namespace Game
{
	class ResourceManagerStd : public ResourceManager
	{
	public:
		ResourceManagerStd() = default;
		~ResourceManagerStd() override;

		VA_Handle createVA(Graphics::VertexArray* va) override;
		VB_Handle createVB(Graphics::VertexBuffer* vb) override;
		SP_Handle createSP(Graphics::ShaderProgram* sp) override;

		Graphics::VertexArray* getVA(VA_Handle va) override;
		Graphics::VertexBuffer* getVB(VB_Handle vb) override;
		Graphics::ShaderProgram* getSP(SP_Handle sp) override;

	private:
		std::vector<Graphics::VertexArray*> m_VAs;
		std::vector<Graphics::VertexBuffer*> m_VBs;
		std::vector<Graphics::ShaderProgram*> m_SPs;
	};
}
