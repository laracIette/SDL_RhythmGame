#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

#include "../../RythmGame.Framework/Window/Window.h"

#include "../../RythmGame.Game/Utils/GameSettings.h"
#include "../../RythmGame.Game/Events/InputManager.h"

#define FONT_SIZE_OPTION         30
#define FONT_SIZE_CATEGORY_TITLE 36

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;

namespace RythmGame::Graphics
{

    class TextTTF
    {
        SDL_Texture *textTexture;
        SDL_Rect dest;
        bool isHoover;

    public:
        TextTTF( std::string text, TTF_Font *font, int posX, int posY );
        ~TextTTF();

        void Update( int posY );

        int X() { return dest.x; }
        int Y() { return dest.y; }
        int W() { return dest.w; }
        int H() { return dest.h; }

        void Draw();

        void Hoover();
        bool IsHoover() { return isHoover; }

        bool IsLeftClicked();
        bool IsRightClicked();
    };

    extern TTF_Font *optionFont;
    extern TTF_Font *categoryTitleFont;

}
