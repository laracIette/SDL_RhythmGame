#include "Accuracy.h"

namespace RythmGame::Game::Gameplay
{

    float Accuracy::GetAccuracy()
    {
        return accuracy;
    }

    void Accuracy::AddValue( int value )
    {
        accuracyHits[value]++;
    }

    void Accuracy::Update()
    {
        if( accuracyHits[0] + accuracyHits[1] + accuracyHits[2] + accuracyHits[3] == 0 )
            accuracy = 100;

        else if( accuracyHits[0] + accuracyHits[1] + accuracyHits[2] == 0 )
            accuracy = 0;

        else
            accuracy = 100 *
                       (float)(6*accuracyHits[0] + 2*accuracyHits[1] + accuracyHits[2]) /
                       (float)(6*(accuracyHits[0] + accuracyHits[1] + accuracyHits[2] + accuracyHits[3]));

        std::string rounded{ std::to_string( (float)((int)(accuracy * 100 + .5) ) / 100 ) };

        std::string newRounded;
        for( int i{ 0 }; i < rounded.size()-4; ++i )
        {
            newRounded += rounded[i];
        }

        SetText( newRounded );
    }

}

