#include "Score.h"

namespace RythmGame::Game::Gameplay
{

    unsigned int Score::GetScore()
    {
        return score;
    }

    void Score::AddScore( unsigned int score )
    {
        SetScore( this->score + score );
    }

    void Score::SetScore( unsigned int score )
    {
        this->score = score;
        SetText( std::to_string( score ) );
    }

}

