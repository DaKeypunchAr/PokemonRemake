#pragma once
#include "Graphics/RenderCommand.hpp"

namespace OpenGL
{
	class RenderCommand : public Graphics::RenderCommand
	{
	public:
		RenderCommand();
		void clearScreen() override;
		void drawArrays(Graphics::RenderMode mode, uint first, uint count) override;
	};

}
