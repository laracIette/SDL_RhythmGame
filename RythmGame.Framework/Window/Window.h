#pragma once

#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include "../../inc/SDL2_mixer-2.6.2/include/SDL_mixer.h"
#include "../../inc/SDL2_ttf-2.20.1/SDL_ttf.h"

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

        void FillRectangle( Rect _dest, RGB _color );
        void DrawBox( Rect _dest, RGB _color );

        SDL_Window *window;
        SDL_Renderer *renderer;
    };

    extern Window *window;

}
