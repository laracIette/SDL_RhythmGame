#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "../Image/Image.h"

#include "../../RythmGame.Game/Utils/Point.h"

using namespace RythmGame::Game::Utils;


namespace RythmGame::Graphics
{

    class Text
    {
        std::string text;
        Rect dest;
        Image *images[36];

        float distance;

    public:
        Text( std::string text, Rect dest );
        ~Text();

        void SetText( std::string text );

        void Draw();
    };


}