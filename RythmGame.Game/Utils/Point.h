#pragma once

#include <SDL_gpu.h>

namespace RythmGame::Game::Utils
{
    template<typename T>
    struct vec2
    {
        T x, y;
    };

    static GPU_Rect *getRectPointer( float x, float y, float w, float h )
    {
        return new GPU_Rect({ x, y, w, h });
    }

}
