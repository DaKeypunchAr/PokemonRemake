#pragma once
#include <cstdint>
#include <string_view>

struct SP_Handle;
namespace Graphics
{
    enum class ShaderDataType
    {
        FLOAT,
        FLOAT2,
        FLOAT3,
        FLOAT4,
    };

    size_t GetShaderDataTypeSize(ShaderDataType type);
    uint8_t GetShaderDataTypeCount(ShaderDataType type);

    class ShaderProgram
    {
    public:
        ShaderProgram() = default;
        ShaderProgram(const ShaderProgram&) = delete;
        ShaderProgram(ShaderProgram&&) = delete;
        ShaderProgram& operator=(const ShaderProgram&) = delete;
        ShaderProgram& operator=(ShaderProgram&&) = delete;

        static SP_Handle Create(const std::string_view& vsSource, const std::string_view& fsSource);
        static SP_Handle Create(const std::string_view& filePath);

        static void Bind(SP_Handle program);

        virtual ~ShaderProgram() = default;
        virtual void bind() const = 0;
    };
}
