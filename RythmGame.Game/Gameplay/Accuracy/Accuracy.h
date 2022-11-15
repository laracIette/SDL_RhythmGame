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
        float accuracy;

    public:
        Accuracy( Rect dest ) : Text( "0", dest, Top )
        {
            accuracy = 0;
        }

        float GetAccuracy();
        void SetAccuracy( float accuracy );
    };

}