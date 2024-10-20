#include "GLFWWindow.hpp"

namespace Game
{
    std::unique_ptr<IWindow> CreateWindow(unsigned int width, unsigned int height)
    {
        // TODO: Make it choose! Not hardcoded!
        return std::make_unique<GLFW::Window>(width, height);
    }
}
