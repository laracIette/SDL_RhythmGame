#pragma once

#include <filesystem>
#include <vector>
#include <string>

#include "../../../../RythmGame.Graphics/Image/Image.h"
#include "../SongTile/SongTile.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::Menu::MapSelection
{

    class Screen
    {
        Image *background;
        std::vector<SongTile *> songs;

    public:
        Screen();
        ~Screen();

        void Draw();
    };

}
