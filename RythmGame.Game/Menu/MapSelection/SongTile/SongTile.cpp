#include "SongTile.h"

namespace RythmGame::Game::Menu::MapSelection
{

    SongTile::SongTile( std::string path )
    {
        song = new Song( path );
        difficultyColor = getSongDifficultyColor( song->GetLevel() );
        song->GetBackground()->SetX( 1920/2 );
        song->GetBackground()->SetW( 1920/3 );
        song->GetBackground()->SetH( 1080/10 );
    }

    SongTile::~SongTile()
    {
    }

    void SongTile::Draw( int posY )
    {
        song->GetBackground()->SetY( (float)1080/10*(float)posY );
        song->GetBackground()->Draw();
    }

    Song *SongTile::GetSong()
    {
        return song;
    }

}