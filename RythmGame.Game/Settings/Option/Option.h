#pragma once

#include <SDL.h>

#include "../../Utils/GameSettings.h"

#include "../../../RythmGame.Graphics/TextTTF/TextTTF.h"

#include "../../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Framework;

namespace RythmGame::Game::Settings
{

    class Option
    {
        TextTTF *text;

        SDL_Rect *backgroundRect;
        RGB backgroundColor;

    public:
        Option( const char *text );
        ~Option();

        void Update( int posY );

        void Draw();
    };

}
