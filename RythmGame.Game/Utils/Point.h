#pragma once

namespace RythmGame::Game::Utils
{
    template<typename T>
    struct vec2
    {
        T x, y;
    };

    struct RGB
    {
        unsigned char r, g, b;
    };

    struct Rect
    {
        float x, y, w, h;
    };

}
