#pragma once

#include <vector>

#include "../Option/Option.h"

#include "../../../RythmGame.Graphics/TextTTF/TextTTF.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::Settings
{
    class Category
    {
        TextTTF *title;

        std::vector<Option *> options;

    public:
        Category( const char *title, std::vector<const char *> optionsVector );
        ~Category();

        int Update( int posY );

        void Draw();
    };
}
