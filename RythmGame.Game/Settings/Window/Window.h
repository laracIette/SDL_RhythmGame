#pragma once

#include "../Categories/Video/Category.h"

#include "../../../RythmGame.Graphics/BoxRoundedCorners.h"

#include "../../Events/InputManager.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Events;


namespace RythmGame::Game::Settings
{

    class Window : public Video::Category
    {
        float posY;

        BoxRoundedCorners *box;

    public:
        Window() : Video::Category( 0 )
        {
        }
        ~Window() {}

        void InitWindow()
        {
            posY = 0;

            box = new BoxRoundedCorners(
                {0, 0, 1920/3, 1080},
                {69, 69, 69},
                "assets/UI/Settings/SettingsRoundedCorner.png"
            );

            InitVideo();
        }

        void UpdateWindow()
        {
            if( (posY + inputManager.WheelMovementY()) >= 0 )
            {
                posY += inputManager.WheelMovementY();
            }

            UpdateVideo();

        }

        void DrawWindow()
        {
            box->Draw();
            DrawVideo();
        }

    };

    extern Window *settingsWindow;

}