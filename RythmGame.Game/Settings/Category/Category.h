#pragma once

#include <vector>
#include <SDL.h>

#include "../Option/Option.h"

#include "../../../RythmGame.Graphics/TextTTF/TextTTF.h"

#include "../../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Framework;

namespace RythmGame::Game::Settings
{
    class Category
    {
        TextTTF *title;

        std::vector<Option *> options;

        SDL_Rect *backgroundRect;
        RGB backgroundColor;

    public:
        Category( const char *title, std::vector<const char *> optionsVector );
        ~Category();

        int Update( int posY );

        void Draw();
    };
}
