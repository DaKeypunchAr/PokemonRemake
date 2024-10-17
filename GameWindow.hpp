#pragma once
#include <memory>

namespace Game
{
    class IWindow {
    public:
        virtual ~IWindow() = default;

        virtual bool shouldClose() const = 0;
        virtual void swapBuffers() const = 0;
        virtual void pollEvents() const = 0;
    };

    std::unique_ptr<IWindow> CreateWindow(unsigned int width, unsigned int height);
}
