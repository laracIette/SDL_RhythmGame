#include "Text.h"

namespace RythmGame::Graphics
{

    Text::Text( std::string text, Rect dest )
    {
        this->text = text;

        const char *characters{ "0123456789abcdefghijklmnopqrstuvwxyz" };
        for( int i{ 0 }; i < 36; ++i )
        {
            std::string character{ characters[i] };
            images[i] = new Image(
                "assets/Skins/BaseSkin/Characters/" + character + ".png",
                {0, 0, 50, 60},
                {0, 0, 50, 60}
            );
        }

        distance = 1.0f;

        this->dest = dest;
    }

    Text::~Text()
    {
    }

    void Text::SetText( std::string text )
    {
        this->text = text;
    }

    void Text::Draw()
    {
        float posX{dest.x - (dest.w/2*distance)*(text.size()-1)};

        for( char letter : text )
        {
            if( (letter >= '0') && (letter <= '9') )
            {
                images[letter-'0']->Draw( {posX, dest.y, dest.w, dest.h} );
            }
            else if( ((letter >= 'a') && (letter <= 'z')) || ((letter >= 'A') && (letter <= 'Z')) )
            {
                images[letter-'a'+10]->Draw( {posX, dest.y, dest.w, dest.h} );
            }

            posX += dest.w*distance;
        }

    }


}