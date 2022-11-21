#pragma once

#include "../../../RythmGame.Graphics/TextTTF/TextTTF.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::Settings
{

    class Option : public TextTTF
    {

    public:
        Option( const char *text )
         : TextTTF( text, optionFont, 10, 0 )
        {}
    };

}
