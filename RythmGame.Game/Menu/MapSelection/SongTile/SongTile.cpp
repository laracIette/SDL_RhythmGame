#include "SongTile.h"

namespace RythmGame::Game::Menu::MapSelection
{

    SongTile::SongTile( std::string path )
    {
        song = new Song( path );
        difficultyColor = getSongDifficultyColor( song->GetLevel() );
        song->GetBackground()->SetX( Default::WIDTH/2 );
        song->GetBackground()->SetW( Default::WIDTH/3 );
        song->GetBackground()->SetH( Default::HEIGHT/10 );
    }

    SongTile::~SongTile()
    {
    }

    void SongTile::Draw( int posY )
    {
        song->GetBackground()->SetY( (float)Default::HEIGHT/10*(float)posY );
        song->GetBackground()->Draw();
    }

    Song *SongTile::GetSong()
    {
        return song;
    }

}