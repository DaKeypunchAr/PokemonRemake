#pragma once
#include "Window.hpp"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

namespace GLFW {

    class Window : public Game::IWindow
    {
    public:
        Window() = delete;
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(const Window&) = delete;
        Window& operator=(Window&&) = delete;

        Window(unsigned int width, unsigned int height);
        ~Window() override;

        bool shouldClose() const override;
        void swapBuffers() const override;
        void pollEvents() const override;
    private:
        GLFWwindow* m_WindowHandle;
    };

}
