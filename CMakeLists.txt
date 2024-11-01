cmake_minimum_required(VERSION 3.29)
project(PokemonRemake)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_library(glad_debug STATIC glad-debug/src/glad.c)
    target_include_directories(glad_debug PUBLIC glad-debug/include)
else()
    add_library(glad STATIC glad/src/glad.c)
    target_include_directories(glad PUBLIC glad/include)
endif()

add_executable(PokemonRemake
        main.cpp
        PokemonRemake/Game.hpp
        PokemonRemake/IO/GameLoader.cpp
        PokemonRemake/IO/GameLoader.hpp
        PokemonRemake/Windowing/Window.cpp
        PokemonRemake/Windowing/Window.hpp
        PokemonRemake/Windowing/GLFWWindow.cpp
        PokemonRemake/Windowing/GLFWWindow.hpp
        PokemonRemake/ResourceManagement/ResourceManager.cpp
        PokemonRemake/ResourceManagement/ResourceManager.hpp
        PokemonRemake/Graphics/VertexArray.cpp
        PokemonRemake/Graphics/VertexArray.hpp
        PokemonRemake/Renderer/Renderer.cpp
        PokemonRemake/Renderer/Renderer.hpp
        PokemonRemake/Graphics/OpenGL/VertexArray.cpp
        PokemonRemake/Graphics/OpenGL/VertexArray.hpp
        PokemonRemake/Graphics/VertexBuffer.cpp
        PokemonRemake/Graphics/VertexBuffer.hpp
        PokemonRemake/Graphics/OpenGL/ShaderProgram.cpp
        PokemonRemake/Graphics/OpenGL/ShaderProgram.hpp
        PokemonRemake/Graphics/RenderCommand.hpp
        PokemonRemake/Graphics/RenderCommand.cpp
        PokemonRemake/Graphics/OpenGL/VertexBuffer.cpp
        PokemonRemake/Graphics/OpenGL/VertexBuffer.hpp
        PokemonRemake/Graphics/ShaderProgram.cpp
        PokemonRemake/Graphics/ShaderProgram.hpp
        PokemonRemake/ResourceManagement/ResourceManagerStd.cpp
        PokemonRemake/ResourceManagement/ResourceManagerStd.hpp
        PokemonRemake/Graphics/OpenGL/RenderCommand.cpp
        PokemonRemake/Graphics/OpenGL/RenderCommand.hpp
        PokemonRemake/Logger/Logger.cpp
        PokemonRemake/Logger/Logger.hpp
        PokemonRemake/Logger/ConsoleLogger.cpp
        PokemonRemake/Logger/ConsoleLogger.hpp
)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(PokemonRemake PRIVATE glfw glad_debug)
else()
    target_link_libraries(PokemonRemake PRIVATE glfw glad)
endif()

target_include_directories(PokemonRemake PRIVATE PokemonRemake)
