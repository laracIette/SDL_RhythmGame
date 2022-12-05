#include "Screen.h"

namespace RythmGame::Game::Menu::MapSelection
{

    Screen::Screen()
    {
        background = new Background(
            "assets/Skins/BaseSkin/Menu/MapSelection/background.png",
            RenderMapSelection
        );

        for( const auto &entry : std::filesystem::directory_iterator( "assets/Maps" ) )
        {
            songs.push_back(
                new SongTile(
                    entry.path()
                )
            );
        }
    }

    Screen::~Screen()
    {
    }

    void Screen::Draw()
    {
    }

/**
 * @returns
 * Song pointer if a SongTile is Clicked
 * else 0
 */
    Song *Screen::Update()
    {
        background->Show();

        for( SongTile *song : songs )
        {
            song->Update( 2 );
        }

        for( SongTile *song : songs )
        {
            song->GetSong()->GetBackground()->Hoover();
            if( song->GetSong()->GetBackground()->IsLeftClicked() )
            {
                return song->GetSong();
            }
        }

        return 0;
    }
}