#include "GameLoader.hpp"
#include "GameWindow.hpp"

int main() {
    // TODO: Add a dialog to choose game file!

    // Loading the Game Resource File.
    GameLoader::Initialize();
    Game::MetaData gameMetaData;
    GameLoader::LoadGameMetaData("/assets/test-game/game.txt", gameMetaData);

    // TODO: Load the Game Resources

    // Run the game!
    std::unique_ptr<Game::IWindow> window = Game::CreateWindow(gameMetaData.windowWidth, gameMetaData.windowHeight);

    while (!window->shouldClose())
    {

        window->swapBuffers();
        window->pollEvents();
    }
}

/*
 * WORKFLOW (PERFECT):
 * 1. Initialize GameLoader.
 * 2. Choose Game using GameLoader.
 * 3. Load Game.
 * 4. Play/Edit Game.
 */