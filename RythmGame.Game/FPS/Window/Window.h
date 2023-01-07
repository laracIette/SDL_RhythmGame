#pragma once

#include <vector>

#include "../../../RythmGame.Graphics/BoxRoundedCorners/BoxRoundedCorners.h"
#include "../../../RythmGame.Graphics/Text/Text.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Game::FPS
{

    class Window
    {
        BoxRoundedCorners *backgroundBox;

        Text *fpsText;

        std::vector<float> fpsValues;

    public:
        Window();
        ~Window();

        void Update( float _value );
    };

}