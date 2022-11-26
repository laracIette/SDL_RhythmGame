#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "../../RythmGame.Game/Utils/Metrics.h"
#include "../../RythmGame.Game/Utils/GameSettings.h"
#include "../../RythmGame.Game/Utils/Point.h"

using namespace RythmGame::Game::Utils;

namespace RythmGame::Framework
{

    class Window
    {

    public:
        Window();
        ~Window();

        void FillRectangle( SDL_Rect dest, RGB color );
        void DrawBox( SDL_Rect rect, RGB color );

        SDL_Window *window;
        SDL_Renderer *renderer;
    };

    extern Window *window;

}
