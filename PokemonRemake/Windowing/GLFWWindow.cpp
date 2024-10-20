#include "GLFWWindow.hpp"

// TODO: Remove #include <iostream> cz it is temporary.
#include <iostream>

namespace GLFW {
    Window::Window(unsigned int width, unsigned int height)
    {
        // TODO: Add a better glfw creation system because we may have multiple windows.
        // TODO: Adda system to use other window hints.
        if (!glfwInit())
        {
            std::cerr << "Failed to initialize GLFW" << std::endl;
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwSetErrorCallback([](int errorCode, const char* description)
        {
            std::cerr << "GLFW Error (" << errorCode << "): " << description << '\n';
        });

        m_WindowHandle = glfwCreateWindow(width, height, "GLFW Window Example", nullptr, nullptr);

        if (!m_WindowHandle)
        {
            std::cerr << "Failed to create GLFW window" << std::endl;
        }
        glfwMakeContextCurrent(m_WindowHandle);

        std::cout << "Made a window successfully!\n";
    }

    Window::~Window()
    {
        // TODO: Add a better glfw destruction system because we may have multiple windows.
        glfwDestroyWindow(m_WindowHandle);
        glfwTerminate();

        std::cout << "Destroyed a window successfully!\n";
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
