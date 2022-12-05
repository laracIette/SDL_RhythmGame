#pragma once

#include <math.h>

namespace RythmGame::Game::Utils
{

    extern int WIDTH;
    extern int HEIGHT;

    extern int FPS;


    template<typename T>
    static inline T deg( T r )
    {
        return r * 180 / M_PI;
    }

    template<typename T>
    static inline T rad( T d )
    {
        return d * M_PI / 180;
    }

    template<typename T>
    static inline T highest( T a, T b )
    {
        return (a > b) ? a : b;

    }
    template<typename T>
    static inline T lowest( T a, T b )
    {
        return (a < b) ? a : b;
    }

}