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
        void Show()    { isShown = true; }
        void UnShow()  { isShown = false; }
    };

}
