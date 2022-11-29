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
        int accuracyHits[4];
        float accuracy;

    public:
    /**
        Accuracy inherits from Text
    */
        Accuracy() :
            Text(
                "100.00",
                {1920/2, 0, 50, 60},
                RenderGameplay,
                8,
                Top
            )
        {
            accuracy = 0;
            for( int &acc : accuracyHits ) acc = 0;
        }

        float GetAccuracy();

        void AddValue( int value );

        void Update();
    };

}