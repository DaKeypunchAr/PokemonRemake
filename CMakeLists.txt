cmake_minimum_required(VERSION 3.29)
project(PokemonRemake)

set(CMAKE_CXX_STANDARD 20)

add_executable(PokemonRemake main.cpp
        Game.hpp
        GameLoader.cpp
        GameLoader.hpp
        GameWindow.cpp
        GameWindow.hpp
        GLFWWindow.cpp
        GLFWWindow.hpp
)
