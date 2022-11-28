#include "Score.h"

namespace RythmGame::Game::Gameplay
{

    unsigned int Score::GetScore()
    {
        return score;
    }

    void Score::AddScore( unsigned int _score )
    {
        SetScore( score + _score );
    }

    void Score::SetScore( unsigned int _score )
    {
        score = _score;
        SetText( std::to_string( score ) );
    }

}

