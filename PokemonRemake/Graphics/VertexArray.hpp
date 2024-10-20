#pragma once
#include <vector>

#include "Graphics/ShaderProgram.hpp"
#include "Graphics/VertexBuffer.hpp"

struct VA_Handle;

namespace Graphics
{

    struct Attribute
    {
        ShaderDataType type;
        const std::string_view name;
        bool normalized = false;
        Attribute(ShaderDataType type, const std::string_view& name, bool normalized = false)
            : type(type), name(name), normalized(normalized) {}
    };

    class VertexArray
    {
    public:
        VertexArray() = default;
        VertexArray(const VertexArray& other) = delete;
        VertexArray(const VertexArray&& other) = delete;
        VertexArray& operator=(const VertexArray&) = delete;
        VertexArray& operator=(VertexArray&&) = delete;

        static ::VA_Handle Create();
        static void Bind(VA_Handle vao);
        static void LinkBuffer(VA_Handle, VB_Handle, const std::vector<Attribute>&);
        static void LinkBuffer(VA_Handle, VB_Handle, const std::initializer_list<Attribute>&);

        virtual ~VertexArray() = default;
        virtual void bind() const = 0;
        virtual void linkBuffer(const VertexBuffer* vb, const std::vector<Attribute>&) const = 0;
        virtual void linkBuffer(const VertexBuffer* vb, const std::initializer_list<Attribute>&) const = 0;
        virtual void getAPI_ID(void* id) = 0;
    };
}
