#include "Screen.h"

namespace RythmGame::Game::Menu::MapSelection
{

    Screen::Screen()
    {
        background = new Image(
            "assets/Skins/BaseSkin/Menu/MapSelection/background.png"
        );

        std::string path;

        for( const auto &entry : std::filesystem::directory_iterator( path ) )
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
        background->Draw();

        for( SongTile *song : songs )
        {
            song->Draw();
        }
    }
}