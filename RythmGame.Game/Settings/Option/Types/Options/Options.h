#pragma once

#include "../../OptionTemplate.h"

namespace RythmGame::Game::Settings::Option
{

    class Options : public OptionTemplate
    {
        std::vector<TextTTF *> options;

        int       index;
        SDL_Rect *backgroundRect;
        RGB       backgroundColor;

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

            backgroundRect = new SDL_Rect();
            backgroundRect->x = resize( 10 );
            backgroundRect->y = 0;
            backgroundRect->w = resize( 1920/3 - 20 );
            backgroundRect->h = resize( options.size() * FONT_SIZE_OPTION );

            backgroundColor = Green;
        }

        std::pair<int, int> Update( int posY );
        void Draw();
    };

}