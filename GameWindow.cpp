#include "GLFWWindow.hpp"

namespace Game
{
    std::unique_ptr<IWindow> CreateWindow(unsigned int width, unsigned int height)
    {
        return std::make_unique<GLFW::Window>(width, height);
    }
}
