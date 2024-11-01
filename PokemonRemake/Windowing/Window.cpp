#include "GLFWWindow.hpp"
#include "Logger/Logger.hpp"

namespace Game
{
    std::unique_ptr<IWindow> CreateWindow(unsigned int width, unsigned int height, WindowingAPI api)
    {
        switch (api)
        {
            case WindowingAPI::GLFW: return std::make_unique<GLFW::Window>(width, height);
            default: Logger::Log("[Game::CreateWindow]: Unknown Windowing API got to be created! Implementation missing!",
                Logger::Severity::ERR);
        }
    }
}
