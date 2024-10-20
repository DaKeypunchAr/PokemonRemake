#pragma once
#include <memory>

#include "Game.hpp"
#include "Graphics/VertexArray.hpp"
#include "Graphics/VertexBuffer.hpp"
#include "Graphics/ShaderProgram.hpp"

class VA_Handle
{
public:
    VA_Handle() = delete;
    VA_Handle(uint8_t idx) : m_Idx(idx) {}

    uint8_t getIdx() { return m_Idx; }

private:
    uint8_t m_Idx;
};

class VB_Handle
{
public:
    VB_Handle() = delete;
    VB_Handle(uint8_t idx) : m_Idx(idx) {}

    uint8_t getIdx() { return m_Idx; }
private:
    uint8_t m_Idx;
};

class SP_Handle
{
public:
    SP_Handle() = delete;
    SP_Handle(uint8_t idx) : m_Idx(idx) {}

    uint8_t getIdx() { return m_Idx; }

private:
    uint8_t m_Idx;
};

namespace Game
{
    class ResourceManager {
    public:
        virtual ~ResourceManager() = default;
        static void LoadResources(const MetaData& gameMetaData);
        static void UnloadResources();

        static VA_Handle CreateVA(Graphics::VertexArray* va);
        static VB_Handle CreateVB(Graphics::VertexBuffer* vb);
        static SP_Handle CreateSP(Graphics::ShaderProgram* sp);

        static Graphics::VertexArray* GetVA(VA_Handle va);
        static Graphics::VertexBuffer* GetVB(VB_Handle vb);
        static Graphics::ShaderProgram* GetSP(SP_Handle sp);

    protected:
        virtual VA_Handle createVA(Graphics::VertexArray* va) = 0;
        virtual VB_Handle createVB(Graphics::VertexBuffer* vb) = 0;
        virtual SP_Handle createSP(Graphics::ShaderProgram* sp) = 0;

        virtual Graphics::VertexArray* getVA(VA_Handle va) = 0;
        virtual Graphics::VertexBuffer* getVB(VB_Handle vb) = 0;
        virtual Graphics::ShaderProgram* getSP(SP_Handle sp) = 0;

    private:
        static std::unique_ptr<ResourceManager> s_Instance;
    };
}
