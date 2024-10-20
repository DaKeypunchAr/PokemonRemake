#pragma once
#include "Graphics/RenderCommand.hpp"

namespace OpenGL
{
	void ClearScreen();
	void DrawArrays(Graphics::RenderMode mode, uint first, uint count);
}
