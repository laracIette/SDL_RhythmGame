#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "../Image/Image.h"

#include "../RenderObject.h"

#include "../../RythmGame.Game/Utils/Point.h"

using namespace RythmGame::Game::Utils;


namespace RythmGame::Graphics
{

    class Text : public RenderObject
    {
        std::string text;
        Rect dest;
        Image *images[37];

        float distance;

        int position;

    public:
        Text( std::string _text, Rect _dest, int _type, int _priority, int _position = Center );
        ~Text();

        void SetText( std::string _text );

        void Draw();
    };


}