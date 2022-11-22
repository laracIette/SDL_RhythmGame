#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Slider : public OptionTemplate
    {

    public:
        Slider( const char *text )
         : OptionTemplate( text )
        {}
    };

}