#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Options : public OptionTemplate
    {
        std::vector<TextTTF *> options;
        int index;

    public:
        Options( std::string text, float value, std::vector<float> options )
         : OptionTemplate( text, value, TypeValue )
        {
            for( float option : options )
            {
                this->options.push_back( new TextTTF( std::to_string( option ), optionFont, 0, 0 ) );
            }

            index = 0;
            for( float option : options )
            {
                if( option == value ) break;
                index++;
            }
        }

        void Update( int posY );
        void Draw();
    };

}