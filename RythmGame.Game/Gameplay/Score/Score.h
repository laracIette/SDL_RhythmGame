#ifndef RYTHMGAME_GAME_GAMEPLAY_SCORE_H
#define RYTHMGAME_GAME_GAMEPLAY_SCORE_H

#include "../../../includes.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;


namespace RythmGame::Game::Gameplay
{

    class Score : public Text
    {
        unsigned int score;

    public:
        Score( Rect dest ) : Text( "0", dest, TopRight )
        {
            score = 0;
        }

        unsigned int GetScore();
        void SetScore( unsigned int score );
        void AddScore( unsigned int score );
    };

}

#endif // RYTHMGAME_GAME_GAMEPLAY_SCORE_H