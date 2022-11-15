#ifndef RYTHMGAME_GAME_GAMEPLAY_PLAYER_H
#define RYTHMGAME_GAME_GAMEPLAY_PLAYER_H

#include "../../../includes.h"

using namespace RythmGame::Game::Utils;
using namespace RythmGame::Game::Events;
using namespace RythmGame::Graphics;

namespace RythmGame::Game::Gameplay
{

    class Player
    {
        static const int nIMAGES{ 6 };

        Image *images[nIMAGES];
        bool isImageShown[nIMAGES]{ false };

        enum ImagesStates {
            HorizontalDefault = 0,
            UpLeft,
            UpRight,
            DownLeft,
            DownRight,
            VerticalDefault
        };

    public:
        Player();
        ~Player();

        void Input();
        void Draw();
    };

}

#endif // RYTHMGAME_GAME_GAMEPLAY_PLAYER_H