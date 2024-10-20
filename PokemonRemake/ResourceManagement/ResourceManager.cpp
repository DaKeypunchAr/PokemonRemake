#include "ResourceManager.hpp"
#include "ResourceManagerStd.hpp"

namespace Game
{
    void ResourceManager::LoadResources(const MetaData& gameMetaData)
    {
        s_Instance = std::make_unique<ResourceManagerStd>();
    }

    void ResourceManager::UnloadResources()
    {
        s_Instance.reset();
    }

    VA_Handle ResourceManager::CreateVA(Graphics::VertexArray* va)
    {
        return s_Instance->createVA(va);
    }

    VB_Handle ResourceManager::CreateVB(Graphics::VertexBuffer* vb)
    {
        return s_Instance->createVB(vb);
    }

    SP_Handle ResourceManager::CreateSP(Graphics::ShaderProgram* sp)
    {
        return s_Instance->createSP(sp);
    }

    Graphics::VertexArray* ResourceManager::GetVA(VA_Handle va)
    {
        return s_Instance->getVA(va);
    }

    Graphics::VertexBuffer* ResourceManager::GetVB(VB_Handle vb)
    {
        return s_Instance->getVB(vb);
    }

    Graphics::ShaderProgram* ResourceManager::GetSP(SP_Handle sp)
    {
        return s_Instance->getSP(sp);
    }

    std::unique_ptr<ResourceManager> ResourceManager::s_Instance;
}
