#pragma once

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
