#pragma once

#include <chrono>


namespace RythmGame::Game::Utils
{
    extern std::chrono::high_resolution_clock::time_point currentTime;
    extern long deltaTime;
    extern std::chrono::high_resolution_clock::time_point offsetTime;
}
