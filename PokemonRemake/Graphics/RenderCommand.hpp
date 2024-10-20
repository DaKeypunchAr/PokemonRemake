#pragma once
#include <sys/types.h>

namespace Graphics
{
	enum class API
	{
		OPENGL,
	};

	enum class RenderMode
	{
		TRIANGLES
	};

	class RenderCommand
	{
	public:
		RenderCommand() = delete;
		RenderCommand(const RenderCommand&) = delete;
		RenderCommand(const RenderCommand&&) = delete;
		RenderCommand& operator=(const RenderCommand&) = delete;
		RenderCommand& operator=(const RenderCommand&&) = delete;

		static void ClearScreen();
		static void DrawArrays(RenderMode mode, uint first, uint count);
	};
}
