#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Value : public OptionTemplate
    {

    public:
        Value( const char *text )
         : OptionTemplate( text )
        {}
    };

}