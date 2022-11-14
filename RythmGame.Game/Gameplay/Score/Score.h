#pragma once

#include <string>

#include "../../../RythmGame.Graphics/Text/Text.h"
#include "../../Utils/Point.h"

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