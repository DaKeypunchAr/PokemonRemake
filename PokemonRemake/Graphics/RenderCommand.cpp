#include "RenderCommand.hpp"
#include "OpenGL/RenderCommand.hpp"

#include "Logger/Logger.hpp"

namespace Graphics
{
	void RenderCommand::InitializeAPI(API api)
	{
		if (s_API != API::NONE) Logger::Log("[RenderCommand::InitializeAPI] API is already initialized!");
		s_API = api;
		switch (api)
		{
		case API::OPENGL:
			s_RenderAPI = std::make_unique<OpenGL::RenderCommand>();
			return;
		case API::NONE: Logger::Log("[RenderCommand::InitializeAPI]: None API received!", Logger::Severity::ERR);
		default:        Logger::Log("[RenderCommand::InitializeAPI]: Unknown API received", Logger::Severity::ERR);
		}
	}

	void RenderCommand::ClearScreen()
	{
		if (s_API == API::NONE) Logger::Log("[RenderCommand::ClearScreen]: API is NOT initialized!");
		s_RenderAPI->clearScreen();
	}

	void RenderCommand::DrawArrays(RenderMode mode, uint first, uint count)
	{
		if (s_API == API::NONE) Logger::Log("[RenderCommand::DrawArrays]: API is NOT initialized!");
		s_RenderAPI->drawArrays(mode, first, count);
	}

	std::unique_ptr<RenderCommand> RenderCommand::s_RenderAPI;
}
