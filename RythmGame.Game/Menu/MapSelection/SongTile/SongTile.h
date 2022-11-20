#pragma once

#include <string>

#include "../../../Utils/GameSettings.h"
#include "../../../../RythmGame.Graphics/Image/Image.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Game::Menu::MapSelection
{

    class SongTile
    {
        Image *songBackground;
        RGB difficultyColor;
        int diff;

    public:
        SongTile( std::string path );
        ~SongTile();

        void Draw();
    };


}
