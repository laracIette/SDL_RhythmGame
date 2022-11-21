#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "../../Utils/GameSettings.h"

#include "../../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Framework;

namespace RythmGame::Game::Settings
{

    class Option
    {
        SDL_Texture *textTexture;
        SDL_Rect dest;

    public:
        Option( const char *text );
        ~Option();

        void Update();

        void Draw();
    };

}
