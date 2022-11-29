#pragma once

#include "../RythmGame.Game/Utils/Point.h"

using namespace RythmGame::Game::Utils;


namespace RythmGame::Graphics
{

    class RenderObject
    {
    public:
        virtual void Draw() {}
        virtual void Draw( Rect _dest ) {}
    };

}
