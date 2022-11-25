#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Value : public OptionTemplate
    {

    public:
        Value( std::string text, float value )
         : OptionTemplate( text, value, TypeValue )
        {
        }

        std::pair<int, int> Update( int posY );
        void Draw();
    };

}