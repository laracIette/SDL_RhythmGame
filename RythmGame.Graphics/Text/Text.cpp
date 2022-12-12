#include "Text.h"

namespace RythmGame::Graphics
{

    Text::Text( std::string _text, Rect _dest, std::vector<std::pair<int, int>> _pairs, int _position )
    {
        text = _text;

        const char *characters{ "0123456789abcdefghijklmnopqrstuvwxyz" };
        for( int i{ 0 }; i < 36; ++i )
        {
            std::string character{ characters[i] };
            images[i] = new Image(
                "assets/Skins/BaseSkin/Characters/" + character + ".png",
                {0, 0, 50, 60},
                _pairs
            );
        }

        images[36] = new Image(
            "assets/Skins/BaseSkin/Characters/point.png",
            {0, 0, 50, 60},
            _pairs
        );

        distance = 1.0f;

        dest = _dest;

        position = _position;


        for( std::pair<int, int> pair : _pairs )
        {
            renderQueue->AddQueue( this, pair.first, pair.second );
        }


    }

    Text::~Text()
    {
    }

    void Text::SetText( std::string _text )
    {
        text = _text;
    }

    void Text::Draw()
    {
        float posX;
        float posY;

        switch( position )
        {
        case Center:
            posX = dest.x - (dest.w/2*distance)*(text.size()-1);
            posY = dest.y;
            break;

        case Top:
            posX = dest.x - (dest.w/2*distance)*(text.size()-1);
            posY = dest.y + dest.h/2;
            break;

        case Bottom:
            posX = dest.x - (dest.w/2*distance)*(text.size()-1);
            posY = dest.y - dest.h/2;
            break;

        case Left:
            posX = dest.x + dest.w/2*distance;
            posY = dest.y;
            break;

        case Right:
            posX = dest.x - dest.w/2*distance - dest.w*(text.size()-1)*distance;
            posY = dest.y;
            break;

        case TopLeft:
            posX = dest.x + dest.w/2*distance;
            posY = dest.y + dest.h/2;
            break;

        case TopRight:
            posX = dest.x - dest.w/2*distance - dest.w*(text.size()-1)*distance;
            posY = dest.y + dest.h/2;
            break;

        case BottomLeft:
            posX = dest.x + dest.w/2*distance;
            posY = dest.y - dest.h/2;
            break;

        case BottomRight:
            posX = dest.x - dest.w/2*distance - dest.w*(text.size()-1)*distance;
            posY = dest.y - dest.h/2;
            break;

        default:
            break;
        }


        for( char letter : text )
        {
            if( (letter >= '0') && (letter <= '9') )
            {
                images[letter-'0']->Draw( {posX, posY, dest.w, dest.h} );
            }
            else if( ((letter >= 'a') && (letter <= 'z')) || ((letter >= 'A') && (letter <= 'Z')) )
            {
                images[letter-'a'+10]->Draw( {posX, posY, dest.w, dest.h} );
            }
            else if( letter == '.' )
            {
                images[36]->Draw( {posX, posY, dest.w, dest.h} );
            }

            posX += dest.w*distance;
        }

    }


}