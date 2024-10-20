#pragma once
#include "Graphics/ShaderProgram.hpp"

namespace OpenGL
{
	class ShaderProgram : public Graphics::ShaderProgram
	{
	public:
		ShaderProgram(const std::string_view& vsSource, const std::string_view& fsSource);
		~ShaderProgram() override;

		void bind() const override;

	private:
		static void compileShader(uint32_t shader);
		void linkProgram() const;

		unsigned int m_API_ID;
	};
}
