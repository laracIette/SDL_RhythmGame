#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

#include "../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Graphics
{

    class TextTTF
    {
        GPU_Image *textTexture;
        GPU_Rect *dest;

    public:
        TextTTF( const char *text, TTF_Font *font, int posX, int posY );
        ~TextTTF();

        void Update( int posY );

        void Draw();
    };

    extern TTF_Font *optionFont;
    extern TTF_Font *categoryTitleFont;

}
