#pragma once
#include <string>

namespace Game
{
    struct MetaData {
        std::string gameTitle;
        unsigned char gameVersion;
        unsigned int windowWidth, windowHeight;
    };
}