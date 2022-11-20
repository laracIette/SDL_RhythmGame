#include "SongTile.h"

namespace RythmGame::Game::Menu::MapSelection
{

    SongTile::SongTile( std::string path )
    {
        difficultyColor = getSongDifficultyColor( diff );
    }

    SongTile::~SongTile()
    {
    }

    void SongTile::Draw()
    {
        songBackground->Draw();
    }

}