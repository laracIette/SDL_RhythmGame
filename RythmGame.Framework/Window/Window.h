#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_gpu.h>

#include "../../RythmGame.Game/Utils/Metrics.h"

using namespace RythmGame::Game::Utils;

namespace RythmGame::Framework
{

    class Window
    {

    public:
        Window();
        ~Window();

        GPU_Target *renderer;
    };

    extern Window *window;

}
