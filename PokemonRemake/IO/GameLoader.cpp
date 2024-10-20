#include "GameLoader.hpp"

namespace GameLoader
{
    void Initialize()
    {
        // TODO: Make a Game Loader instance.
    }

    void LoadGameMetaData(const std::filesystem::path& gameDataPath, Game::MetaData& gameInfo)
    {
        // TODO: Load the game meta data actually!
        gameInfo.gameTitle = "Test Game";
        gameInfo.gameVersion = 0;
        gameInfo.windowWidth = 720;
        gameInfo.windowHeight = 720;
    }

}
