#pragma once

#include "Categories/Video/Category.h"
#include "Categories/Sound/Category.h"

#include "../../RythmGame.Graphics/BoxRoundedCorners.h"

#include "../Events/InputManager.h"

using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Events;


namespace RythmGame::Game::Settings
{

    class Window : public Video::Category, public Sound::Category
    {
        float posY;

        BoxRoundedCorners *box;

    public:
        Window() : Video::Category( 0 ), Sound::Category( GetVideoHeight() )
        {
        }

        void InitWindow()
        {
            posY = 0;

            box = new BoxRoundedCorners(
                {0, 0, resize( 1920/3 ), resize( 1080 )},
                {69, 69, 69},
                "assets/UI/Settings/SettingsRoundedCorner.png"
            );

            InitVideo();
            InitSound();
        }

        void Scroll()
        {
            if( (posY + inputManager.WheelMovementY()) >= 0 )
            {
                posY += inputManager.WheelMovementY();
                ScrollVideo( posY );
                ScrollSound( posY );
            }
        }

        void UpdateWindow()
        {
            UpdateVideo();
            UpdateSound();
        }

        void DrawWindow()
        {
            box->Draw();

            DrawVideo();
            DrawSound();
        }

    };

    extern Window *settingsWindow;

}