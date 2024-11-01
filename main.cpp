#include "PokemonRemake/IO/GameLoader.hpp"
#include "PokemonRemake/Windowing/Window.hpp"

#include "Graphics/RenderCommand.hpp"
#include "Graphics/VertexArray.hpp"
#include "Graphics/VertexBuffer.hpp"
#include "Graphics/ShaderProgram.hpp"
#include "Logger/Logger.hpp"
#include "ResourceManagement/ResourceManager.hpp"

int main()
{
    // TODO: Add a dialog to choose game file!

    // Loading the Game Resource File.
    Logger::Initialize();
    GameLoader::Initialize();
    Game::MetaData gameMetaData;
    GameLoader::LoadGameMetaData("/assets/test-game/game", gameMetaData);

    Game::ResourceManager::LoadResources(gameMetaData);

    // Run the game!
    std::unique_ptr<Game::IWindow> window = Game::CreateWindow(gameMetaData.windowWidth, gameMetaData.windowHeight);
    Graphics::RenderCommand::InitializeAPI(Graphics::API::OPENGL);

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