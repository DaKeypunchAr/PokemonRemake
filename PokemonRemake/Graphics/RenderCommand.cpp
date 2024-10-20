#include "RenderCommand.hpp"
#include "OpenGL/RenderCommand.hpp"

namespace Graphics
{
	void RenderCommand::ClearScreen()
	{
		OpenGL::ClearScreen();
	}

	void RenderCommand::DrawArrays(RenderMode mode, uint first, uint count)
	{
		OpenGL::DrawArrays(mode, first, count);
	}

}
