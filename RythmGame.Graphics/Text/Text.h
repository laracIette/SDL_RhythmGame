#ifndef RYTHMGAME_GRAPHICS_TEXT_H
#define RYTHMGAME_GRAPHICS_TEXT_H


#include "../../includes.h"

using namespace RythmGame::Game::Utils;


namespace RythmGame::Graphics
{
    enum Positions {
        Center = 0,
        Top,
        Left,
        Right,
        Bottom,
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    class Text
    {
        std::string text;
        Rect dest;
        Image *images[37];

        float distance;

        int position;

    public:
        Text( std::string text, Rect dest, int position );
        ~Text();

        void SetText( std::string text );

        void Draw();
    };


}

#endif // RYTHMGAME_GRAPHICS_TEXT_H