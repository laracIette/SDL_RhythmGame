#pragma once

#include <filesystem>
#include <vector>
#include <string>

#include "../../../../RythmGame.Graphics/Background.h"
#include "../SongTile/SongTile.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::Menu::MapSelection
{

    class Screen
    {
        Background *background;
        std::vector<SongTile *> songs;

    public:
        Screen();
        ~Screen();

        Song *Update();
    };

}
