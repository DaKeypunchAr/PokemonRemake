#pragma once
#include "GameWindow.hpp"

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

        bool shouldClose() const override;
        void swapBuffers() const override;
        void pollEvents() const override;
    };

}
