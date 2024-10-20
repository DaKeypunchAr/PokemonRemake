#pragma once
#include "Graphics/VertexArray.hpp"

namespace OpenGL
{
    class VertexArray : public Graphics::VertexArray {
    public:
        VertexArray();
        ~VertexArray() override;

        void bind() const override;
        void linkBuffer(const Graphics::VertexBuffer* vb, const std::initializer_list<Graphics::Attribute>&) const override;
        void linkBuffer(const Graphics::VertexBuffer* vb, const std::vector<Graphics::Attribute>&) const override;
        void getAPI_ID(void* id) override;
    private:
        unsigned int m_API_ID;
    };
}
