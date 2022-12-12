#pragma once

#include <chrono>



namespace RythmGame::Game::Utils
{
    #define Microseconds std::chrono::microseconds
    #define Milliseconds std::chrono::milliseconds

    template <typename T>
    static long getDuration(
        std::chrono::high_resolution_clock::time_point t1,
        std::chrono::high_resolution_clock::time_point t2
    )
    {
        return std::chrono::duration_cast<T>(t1 - t2).count();
    }

    extern std::chrono::high_resolution_clock::time_point currentTime;
    extern std::chrono::high_resolution_clock::time_point lastFrameTime;
    extern std::chrono::high_resolution_clock::time_point lastRenderTime;
    extern std::chrono::high_resolution_clock::time_point offsetTime;
    extern float deltaTime;

}
