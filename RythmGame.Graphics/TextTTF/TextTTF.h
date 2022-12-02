#pragma once

#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include "../../inc/SDL2_ttf-2.20.1/SDL_ttf.h"
#include <iostream>
#include <string>

#include "../../RythmGame.Framework/Window/Window.h"

#include "../../RythmGame.Game/Utils/GameSettings.h"
#include "../../RythmGame.Game/Events/InputManager.h"

#include "../Renderable.h"

#include "../RenderQueue/RenderQueue.h"

#define FONT_SIZE_OPTION                     30
#define FONT_SIZE_CATEGORY_TITLE             36
#define FONT_SIZE_OPTION_WITH_SPACE          42
#define FONT_SIZE_CATEGORY_TITLE_WITH_SPACE  50

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;

namespace RythmGame::Graphics
{

    class TextTTF : public Renderable
    {
        SDL_Texture *textTexture;
        SDL_Rect dest;
        bool isHoover;

    public:
    /**
     * DONT RESIZE RECT BEFORE FUNCTION CALL
     */
        TextTTF( std::string _text, TTF_Font *_font, int _posX, int _posY, int _type, int _priority );
        ~TextTTF();

        void Update( int _posY );

        int X() { return dest.x; }
        int Y() { return dest.y; }
        int W() { return dest.w; }
        int H() { return dest.h; }

        SDL_Rect GetRect() { return dest; }

        void Draw();

        void Hoover();
        bool IsHoover() { return isHoover; }

        bool IsHooverLeftClicked();
        bool IsHooverRightClicked();
        bool IsNotHooverLeftClicked();
        bool IsNotHooverRightClicked();
    };

    extern TTF_Font *optionFont;
    extern TTF_Font *categoryTitleFont;

}
