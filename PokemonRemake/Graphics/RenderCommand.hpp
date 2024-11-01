#pragma once
#include <memory>
#include <sys/types.h>

namespace Graphics
{
	enum class API
	{
		NONE,
		OPENGL,
	};

	enum class RenderMode
	{
		TRIANGLES
	};

	class RenderCommand
	{
	public:
		RenderCommand() = default;
		virtual ~RenderCommand() = default;

		static void InitializeAPI(API api = API::OPENGL);
		static void ClearScreen();
		static void DrawArrays(RenderMode mode, uint first, uint count);

		inline static API GetAPI() { return s_API; }

		virtual void clearScreen() = 0;
		virtual void drawArrays(RenderMode mode, uint first, uint count) = 0;

	private:
		inline static API s_API = API::NONE;
		static std::unique_ptr<RenderCommand> s_RenderAPI;
	};
}
