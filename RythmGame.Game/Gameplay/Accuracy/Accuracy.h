#pragma once

#include <string>

#include "../../../RythmGame.Graphics/Text/Text.h"
#include "../../Utils/Point.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;


namespace RythmGame::Game::Gameplay
{

    class Accuracy : public Text
    {
        unsigned int accuracyHits[4];
        float accuracy;

    public:
        Accuracy( Rect dest ) : Text( "100.00", dest, Top )
        {
            accuracy = 0;
            for( unsigned int &acc : accuracyHits ) acc = 0;
        }

        float GetAccuracy();

        void AddValue( int value );

        void Update();
    };

}