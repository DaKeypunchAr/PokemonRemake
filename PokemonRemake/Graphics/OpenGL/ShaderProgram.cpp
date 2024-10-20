#include "ShaderProgram.hpp"

#include <iostream>
#include <glad/glad.h>

namespace OpenGL {
	ShaderProgram::ShaderProgram(const std::string_view& vsSource, const std::string_view& fsSource)
		: Graphics::ShaderProgram(), m_API_ID(glCreateProgram())
	{
		unsigned int vs = glCreateShader(GL_VERTEX_SHADER), fs = glCreateShader(GL_FRAGMENT_SHADER);
		const char* vsSourceCStr = vsSource.data(), *fsSourceCStr = fsSource.data();
		glShaderSource(vs, 1, &vsSourceCStr, nullptr);
		glShaderSource(fs, 1, &fsSourceCStr, nullptr);

		compileShader(vs);
		compileShader(fs);

		glAttachShader(m_API_ID, vs);
		glAttachShader(m_API_ID, fs);

		linkProgram();

		glDetachShader(m_API_ID, vs);
		glDetachShader(m_API_ID, fs);

		glDeleteShader(vs);
		glDeleteShader(fs);
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_API_ID);
	}

	void ShaderProgram::bind() const
	{
		glUseProgram(m_API_ID);
	}

	void ShaderProgram::compileShader(uint32_t shader)
	{
		glCompileShader(shader);

		int compileStatus;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);

		if (compileStatus == GL_FALSE)
		{
			int length = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
			char* infoLog = static_cast<char*>(alloca(length + 1));
			glGetShaderInfoLog(shader, length, &length, infoLog);
			std::cerr << infoLog << '\n';
		}
	}

	void ShaderProgram::linkProgram() const
	{
		glLinkProgram(m_API_ID);

		int linkStatus;
		glGetProgramiv(m_API_ID, GL_LINK_STATUS, &linkStatus);

		if (linkStatus == GL_FALSE)
		{
			int length = 0;
			glGetProgramiv(m_API_ID, GL_INFO_LOG_LENGTH, &length);
			char* infoLog = static_cast<char*>(alloca(length + 1));
			glGetProgramInfoLog(m_API_ID, length, &length, infoLog);
			std::cerr << infoLog << '\n';
		}
	}
}
