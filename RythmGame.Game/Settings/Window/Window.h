#pragma once

#include "../Categories/Video/Category.h"

#include "../../../RythmGame.Graphics/BoxRoundedCorners.h"

#include "../../Events/InputManager.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Events;


namespace RythmGame::Game::Settings
{

    class Window
    {
        float posY;

        BoxRoundedCorners *box;

        Video::Category *categoryVideo;

    public:
        Window();
        ~Window();

        void Update();

        void Draw();
    };

}