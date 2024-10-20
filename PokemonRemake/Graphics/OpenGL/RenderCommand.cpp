#include "RenderCommand.hpp"

#include <glad/glad.h>

namespace OpenGL
{
	void ClearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void DrawArrays(Graphics::RenderMode mode, uint first, uint count)
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
