#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "../Image/Image.h"

#include "../../RythmGame.Game/Utils/Point.h"

using namespace RythmGame::Game::Utils;


namespace RythmGame::Graphics
{
    enum Positions {
        Center = 0,
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight
    };

    class Text
    {
        std::string text;
        Rect dest;
        Image *images[36];

        float distance;

        int position;

    public:
        Text( std::string text, Rect dest, int position );
        ~Text();

        void SetText( std::string text );

        void Draw();
    };


}