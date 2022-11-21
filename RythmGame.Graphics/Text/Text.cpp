#include "Text.h"

namespace RythmGame::Graphics
{

    Text::Text( std::string text, GPU_Rect *dest, int position )
    {
        this->text = text;

        const char *characters{ "0123456789abcdefghijklmnopqrstuvwxyz" };
        for( int i{ 0 }; i < 36; ++i )
        {
            std::string character{ characters[i] };
            images[i] = new Image(
                "assets/Skins/BaseSkin/Characters/" + character + ".png",
                getRectPointer(0, 0, 50, 60)
            );
        }

        images[36] = new Image(
            "assets/Skins/BaseSkin/Characters/point.png",
            getRectPointer(0, 0, 50, 60)
        );

        distance = 1.0f;

        this->dest = dest;

        this->position = position;
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
        float posX;
        float posY;

        switch( position )
        {
        case Center:
            posX = dest->x - (dest->w/2*distance)*(text.size()-1);
            posY = dest->y;
            break;

        case Top:
            posX = dest->x - (dest->w/2*distance)*(text.size()-1);
            posY = dest->y + dest->h/2;
            break;

        case Bottom:
            posX = dest->x - (dest->w/2*distance)*(text.size()-1);
            posY = dest->y - dest->h/2;
            break;

        case Left:
            posX = dest->x + dest->w/2*distance;
            posY = dest->y;
            break;

        case Right:
            posX = dest->x - dest->w/2*distance - dest->w*(text.size()-1)*distance;
            posY = dest->y;
            break;

        case TopLeft:
            posX = dest->x + dest->w/2*distance;
            posY = dest->y + dest->h/2;
            break;

        case TopRight:
            posX = dest->x - dest->w/2*distance - dest->w*(text.size()-1)*distance;
            posY = dest->y + dest->h/2;
            break;

        case BottomLeft:
            posX = dest->x + dest->w/2*distance;
            posY = dest->y - dest->h/2;
            break;

        case BottomRight:
            posX = dest->x - dest->w/2*distance - dest->w*(text.size()-1)*distance;
            posY = dest->y - dest->h/2;
            break;

        default:
            break;
        }


        for( char letter : text )
        {
            if( (letter >= '0') && (letter <= '9') )
            {
                images[letter-'0']->Draw( getRectPointer(posX, posY, dest->w, dest->h) );
            }
            else if( ((letter >= 'a') && (letter <= 'z')) || ((letter >= 'A') && (letter <= 'Z')) )
            {
                images[letter-'a'+10]->Draw( getRectPointer(posX, posY, dest->w, dest->h) );
            }
            else if( letter == '.' )
            {
                images[36]->Draw( getRectPointer(posX, posY, dest->w, dest->h) );
            }

            posX += dest->w*distance;
        }

    }


}