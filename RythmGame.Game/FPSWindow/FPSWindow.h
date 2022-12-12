#pragma once

#include "../../RythmGame.Graphics/BoxRoundedCorners.h"
#include "../../RythmGame.Graphics/Text/Text.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game
{

    class FPSWindow
    {
        BoxRoundedCorners *backgroundBox;

        Text *fpsText;

    public:
        FPSWindow();
        ~FPSWindow();

        void Update( float _value );
    };

}