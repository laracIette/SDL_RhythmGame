#pragma once

#include <string>

#include "../../../Utils/GameSettings.h"
#include "../../../Song/Song.h"
#include "../../../../RythmGame.Graphics/Image/Image.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game;

namespace RythmGame::Game::Menu::MapSelection
{

    class SongTile
    {
        RGB difficultyColor;

        Song *song;

    public:
        SongTile( std::string path );
        ~SongTile();

        void Update( int posY );

        Song *GetSong();
    };


}
