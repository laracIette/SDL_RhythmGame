#pragma once

#include <string>

#include "../../../RythmGame.Graphics/Text/Text.h"
#include "../../Utils/Point.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;


namespace RythmGame::Game::Gameplay
{

    class Combo : public Text
    {
        unsigned int combo;

    public:
        Combo( Rect dest ) : Text( "0", dest, BottomLeft )
        {
            combo = 0;
        }

        unsigned int GetCombo();
        void SetCombo( unsigned int combo );
        void AddCombo( unsigned int combo = 1 );
    };

}