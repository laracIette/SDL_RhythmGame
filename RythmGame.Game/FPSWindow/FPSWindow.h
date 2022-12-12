#pragma once

#include "../../RythmGame.Graphics/BoxRoundedCorners.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game
{

    class FPSWindow
    {
        BoxRoundedCorners *backgroundBox;

    public:
        FPSWindow();
        ~FPSWindow();
    };

}