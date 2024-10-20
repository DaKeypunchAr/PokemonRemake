#include "ResourceManagerStd.hpp"

namespace Game
{
	ResourceManagerStd::~ResourceManagerStd()
	{
		for (const Graphics::VertexArray* va : m_VAs)
			delete va;

		for (const Graphics::VertexBuffer* vb : m_VBs)
			delete vb;

		for (const Graphics::ShaderProgram* sp : m_SPs)
			delete sp;
	}

	VA_Handle ResourceManagerStd::createVA(Graphics::VertexArray* va)
	{
		m_VAs.push_back(va);
		return m_VAs.size() - 1;
	}

	VB_Handle ResourceManagerStd::createVB(Graphics::VertexBuffer* vb)
	{
		m_VBs.push_back(vb);
		return m_VBs.size() - 1;
	}

	SP_Handle ResourceManagerStd::createSP(Graphics::ShaderProgram* sp)
	{
		m_SPs.push_back(sp);
		return m_SPs.size() - 1;
	}

	Graphics::VertexArray* ResourceManagerStd::getVA(VA_Handle va)
	{
		return m_VAs[va.getIdx()];
	}

	Graphics::VertexBuffer* ResourceManagerStd::getVB(VB_Handle vb)
	{
		return m_VBs[vb.getIdx()];
	}

	Graphics::ShaderProgram* ResourceManagerStd::getSP(SP_Handle sp)
	{
		return m_SPs[sp.getIdx()];
	}
}
