#pragma once

#include <SDL.h>

namespace RythmGame::Game::Utils
{
    template<typename T>
    struct vec2
    {
        T x, y;
    };

    struct Rect
    {
        float x, y, w, h;
    };

}
