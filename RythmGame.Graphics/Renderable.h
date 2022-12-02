#pragma once

#include "../RythmGame.Game/Utils/Point.h"

using namespace RythmGame::Game::Utils;


namespace RythmGame::Graphics
{

    class Renderable
    {
        bool isShown;

    public:

        virtual void Draw() {}

        bool IsShown() { return isShown; }
        bool IsShown( bool _b )
        {
            isShown = _b;
            return isShown;
        }
    };

}
