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

    void SongTile::Update( float _y )
    {
        song->GetBackground()->SetY( 1080/10*_y );
        song->GetBackground()->Show();
    }

    Song *SongTile::GetSong()
    {
        return song;
    }

}