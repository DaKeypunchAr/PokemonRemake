#include "GLFWWindow.hpp"
#include "Logger/Logger.hpp"

namespace GLFW {
    Window::Window(unsigned int width, unsigned int height)
    {
        // TODO: Add a better glfw creation system because we may have multiple windows.
        // TODO: Adda system to use other window hints.
        if (!glfwInit())
        {
            Logger::Log("Failed to initialize GLFW", Logger::Severity::ERR);
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwSetErrorCallback([](int errorCode, const char* description)
        {
            Logger::LogF("[GLFW Error]: Err code: %d, Description: %s", Logger::Severity::ERR, errorCode, description);
        });

        m_WindowHandle = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), "GLFW Window Example", nullptr, nullptr);

        if (!m_WindowHandle)
        {
            Logger::Log("Failed to create GLFW Window!", Logger::Severity::ERR);
        }
        glfwMakeContextCurrent(m_WindowHandle);

        Logger::DLog("Created a GLFW Window successfully!");
    }

    Window::~Window()
    {
        // TODO: Add a better glfw destruction system because we may have multiple windows.
        glfwDestroyWindow(m_WindowHandle);
        glfwTerminate();

        Logger::DLog("Destroyed a GLFW Window successfully!");
    }

    bool Window::shouldClose() const
    {
        return glfwWindowShouldClose(m_WindowHandle);
    }

    void Window::swapBuffers() const
    {
        glfwSwapBuffers(m_WindowHandle);
    }

    void Window::pollEvents() const
    {
        // TODO: Make it so that it updates only the selected window. And hence add that window selection system.
        glfwPollEvents();
    }

}
