#include "ShaderProgram.hpp"
#include "OpenGL/ShaderProgram.hpp"

#include "ResourceManagement/ResourceManager.hpp"

namespace Graphics
{
	size_t GetShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::FLOAT:
				return sizeof(float);
			case ShaderDataType::FLOAT2:
				return sizeof(float) * 2;
			case ShaderDataType::FLOAT3:
				return sizeof(float) * 3;
			case ShaderDataType::FLOAT4:
				return sizeof(float) * 4;
			default:
				return 0;
		}
	}

	uint8_t GetShaderDataTypeCount(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::FLOAT:
				return 1;
			case ShaderDataType::FLOAT2:
				return 2;
			case ShaderDataType::FLOAT3:
				return 3;
			case ShaderDataType::FLOAT4:
				return 4;
			default:
				return 0;
		}
	}

	SP_Handle ShaderProgram::Create(const std::string_view& vsSource, const std::string_view& fsSource)
	{
		ShaderProgram* sp = new OpenGL::ShaderProgram(vsSource, fsSource);
		return Game::ResourceManager::CreateSP(sp);
	}

	SP_Handle ShaderProgram::Create(const std::string_view& filePath)
	{
		// TODO: Load the source files!
		ShaderProgram* sp = new OpenGL::ShaderProgram("", "");
		return Game::ResourceManager::CreateSP(sp);
	}

	void ShaderProgram::Bind(SP_Handle sp)
	{
		Game::ResourceManager::GetSP(sp)->bind();
	}
}
