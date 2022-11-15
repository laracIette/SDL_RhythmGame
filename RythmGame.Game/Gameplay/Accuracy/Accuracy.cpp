#include "Accuracy.h"

namespace RythmGame::Game::Gameplay
{

    float Accuracy::GetAccuracy()
    {
        return accuracy;
    }

    void Accuracy::SetAccuracy( float accuracy )
    {
        this->accuracy = accuracy;
        std::string rounded{ std::to_string( (float)((int)(accuracy * 100 + .5) ) / 100 ) };

        std::string newRounded;
        for( int i{ 0 }; i < rounded.size()-4; ++i )
        {
            newRounded += rounded[i];
        }

        SetText( newRounded );
    }

}

