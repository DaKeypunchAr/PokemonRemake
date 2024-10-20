#include "PokemonRemake/IO/GameLoader.hpp"
#include "PokemonRemake/Windowing/Window.hpp"
#include "glad-debug/include/glad/glad.h"

// TODO: Remove GLFW & iostream include from main.cpp
#define GLFW_INCLUDE_NONE
#include <iostream>
#include <GLFW/glfw3.h>

#include "Graphics/RenderCommand.hpp"
#include "Graphics/VertexArray.hpp"
#include "Graphics/VertexBuffer.hpp"
#include "Graphics/OpenGL/ShaderProgram.hpp"
#include "ResourceManagement/ResourceManager.hpp"

int main()
{
    // TODO: Add a dialog to choose game file!

    // Loading the Game Resource File.
    GameLoader::Initialize();
    Game::MetaData gameMetaData;
    GameLoader::LoadGameMetaData("/assets/test-game/game", gameMetaData);

    Game::ResourceManager::LoadResources(gameMetaData);

    // Run the game!
    std::unique_ptr<Game::IWindow> window = Game::CreateWindow(gameMetaData.windowWidth, gameMetaData.windowHeight);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Glad was failed to initialize!\n";
        return -1;
    }
    // Enable the OpenGL error callback
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); // Ensures errors are reported immediately

    // Set up the OpenGL debug message callback using a lambda function
    glDebugMessageCallback(
        [](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
           const GLchar* message, const void* userParam)
           {
            std::cerr << "OpenGL Error: " << message << std::endl;

            std::cerr << "Source: ";
            switch (source)
            {
                case GL_DEBUG_SOURCE_API:             std::cerr << "API"; break;
                case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cerr << "Window System"; break;
                case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cerr << "Shader Compiler"; break;
                case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cerr << "Third Party"; break;
                case GL_DEBUG_SOURCE_APPLICATION:     std::cerr << "Application"; break;
                case GL_DEBUG_SOURCE_OTHER:           std::cerr << "Other"; break;
                default: std::cerr << "Unknown";
            }
            std::cerr << std::endl;

            std::cerr << "Type: ";
            switch (type)
            {
                case GL_DEBUG_TYPE_ERROR:               std::cerr << "Error"; break;
                case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cerr << "Deprecated Behavior"; break;
                case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cerr << "Undefined Behavior"; break;
                case GL_DEBUG_TYPE_PORTABILITY:         std::cerr << "Portability Issue"; break;
                case GL_DEBUG_TYPE_PERFORMANCE:         std::cerr << "Performance Issue"; break;
                case GL_DEBUG_TYPE_MARKER:              std::cerr << "Marker"; break;
                case GL_DEBUG_TYPE_PUSH_GROUP:          std::cerr << "Push Group"; break;
                case GL_DEBUG_TYPE_POP_GROUP:           std::cerr << "Pop Group"; break;
                case GL_DEBUG_TYPE_OTHER:               std::cerr << "Other"; break;
                default: std::cerr << "Unknown";
            }
            std::cerr << std::endl;

            std::cerr << "Severity: ";
            switch (severity)
            {
                case GL_DEBUG_SEVERITY_HIGH:         std::cerr << "High"; break;
                case GL_DEBUG_SEVERITY_MEDIUM:       std::cerr << "Medium"; break;
                case GL_DEBUG_SEVERITY_LOW:          std::cerr << "Low"; break;
                case GL_DEBUG_SEVERITY_NOTIFICATION: std::cerr << "Notification"; break;
                default: std::cerr << "Unknown";
            }
            std::cerr << std::endl;

            std::cerr << "ID: " << id << std::endl;
            std::cerr << "--------------------------" << std::endl;
        },
        nullptr
    );

    VA_Handle VAO = Graphics::VertexArray::Create();

    VB_Handle VBO = Graphics::VertexBuffer::Create();

    float vertices[3 * 3]
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
    };

    Graphics::VertexBuffer::FillData(VBO, vertices, sizeof(vertices));

    Graphics::VertexArray::LinkBuffer(VAO, VBO, {
        { Graphics::ShaderDataType::FLOAT3, "Position" },
    });

    Graphics::VertexArray::Bind(VAO);

    const char* vsSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main() {\n\tgl_Position = vec4(aPos, 1.0);\n}";

    const char* fsSource = "#version 330 core\n"
    "out vec4 oColor;\n"
    "void main() {\n\toColor = vec4(1.0, 1.0, 1.0, 1.0);\n}";

    SP_Handle colorProgram = Graphics::ShaderProgram::Create(vsSource, fsSource);
    Graphics::ShaderProgram::Bind(colorProgram);

    while (!window->shouldClose())
    {
        Graphics::RenderCommand::ClearScreen();

        Graphics::RenderCommand::DrawArrays(Graphics::RenderMode::TRIANGLES, 0, 3);

        window->swapBuffers();
        window->pollEvents();
    }

    Game::ResourceManager::UnloadResources();
}

/*
 * WORKFLOW (PERFECT):
 * 1. Initialize GameLoader.
 * 2. Choose Game using GameLoader.
 * 3. Load Game.
 * 4. Play/Edit Game.
 */