#include "RenderCommand.hpp"

#include <glad/glad.h>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Logger/Logger.hpp"

namespace OpenGL
{
	RenderCommand::RenderCommand()
	{
		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
		{
			Logger::Log("Glad was failed to initialize!", Logger::Severity::ERR);
		}

		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

		glDebugMessageCallback(
			[](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
				const GLchar* message, const void* userParam)
			{

				auto sourceToStr = [](GLenum source)-> std::string_view
				{
					switch (source)
					{
						case GL_DEBUG_SOURCE_API:             return "API";
						case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   return "Window System";
						case GL_DEBUG_SOURCE_SHADER_COMPILER: return "Shader Compiler";
						case GL_DEBUG_SOURCE_THIRD_PARTY:     return "Third Party";
						case GL_DEBUG_SOURCE_APPLICATION:     return "Application";
						case GL_DEBUG_SOURCE_OTHER:           return "Other";
						default: return "Unknown";
					}
				};

				auto typeToStr = [](GLenum type)-> std::string_view
				{
					switch (type)
					{
						case GL_DEBUG_TYPE_ERROR:               return "Error";
						case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "Deprecated Behavior";
						case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  return "Undefined Behavior";
						case GL_DEBUG_TYPE_PORTABILITY:         return "Portability Issue";
						case GL_DEBUG_TYPE_PERFORMANCE:         return "Performance Issue";
						case GL_DEBUG_TYPE_MARKER:              return "Marker";
						case GL_DEBUG_TYPE_PUSH_GROUP:          return "Push Group";
						case GL_DEBUG_TYPE_POP_GROUP:           return "Pop Group";
						case GL_DEBUG_TYPE_OTHER:               return "Other";
						default: return "Unknown";;
					}
	            };

				auto severityToEnumClass = [](GLenum severity) -> Logger::Severity
				{
					switch (severity)
					{
						case GL_DEBUG_SEVERITY_HIGH:         return Logger::Severity::ERR;
						case GL_DEBUG_SEVERITY_MEDIUM:       return Logger::Severity::WARN;
						case GL_DEBUG_SEVERITY_LOW:          return Logger::Severity::WARN;
						case GL_DEBUG_SEVERITY_NOTIFICATION:
						default:							 return Logger::Severity::INFO;
					}
				};

				Logger::DLogF("[OpenGL Callback]:\n\tSource: %s\n\tType: %s\nMessage: %s",
					severityToEnumClass(severity),
					sourceToStr(source),
					typeToStr(type),
					message);
			}, nullptr);
	}

	void RenderCommand::clearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void RenderCommand::drawArrays(Graphics::RenderMode mode, uint first, uint count)
	{
		static auto getGLMode = [&](Graphics::RenderMode mode)
		{
			switch (mode)
			{
			case Graphics::RenderMode::TRIANGLES:
				return GL_TRIANGLES;
			default:
				return 0;
			}
		};
		glDrawArrays(getGLMode(mode), first, count);
	}
}
