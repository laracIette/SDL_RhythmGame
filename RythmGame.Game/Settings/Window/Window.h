#pragma once

#include "../Categories/Video/Category.h"
#include "../Categories/Sound/Category.h"

#include "../../../RythmGame.Graphics/BoxRoundedCorners/BoxRoundedCorners.h"

#include "../../Events/InputManager.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Events;


namespace RythmGame::Game::Settings
{

    class Window : public Video::Category, public Sound::Category
    {
        float posY;
        int count;

        BoxRoundedCorners *box;

        bool isHide;

    public:
        Window() :
            Video::Category( 0 ),
            Sound::Category( GetVideoHeight() )
        {
            isHide = true;
        }

        void InitWindow();
        void Scroll();
        void UpdateWindow();

        bool IsHide() { return isHide; }

    };

    extern Window *settingsWindow;

}