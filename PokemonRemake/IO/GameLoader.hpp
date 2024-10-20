#pragma once

// TODO: Switch to absolute path instead of relative path. And resolve the error that comes with it.
#include "Game.hpp"

#include <filesystem>

namespace Game
{
    struct MetaData;
}

namespace GameLoader
{
    void Initialize();
    void LoadGameMetaData(const std::filesystem::path& gameDataPath, Game::MetaData& gameInfo);
}
