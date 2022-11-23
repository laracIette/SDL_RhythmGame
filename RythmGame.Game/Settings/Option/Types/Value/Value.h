#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Value : public OptionTemplate
    {
        int value;

    public:
        Value( std::string text, int value )
         : OptionTemplate( text )
        {
            this->value = value;
        }

        void Update( int posY );
        void Draw();
    };

}