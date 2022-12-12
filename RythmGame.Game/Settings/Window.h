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
        int count;

        BoxRoundedCorners *box;

    public:
        Window() :
            Video::Category( 0 ),
            Sound::Category( GetVideoHeight() )
        {
        }

        void InitWindow()
        {
            posY = 0;

            box = new BoxRoundedCorners(
                {0, 0, 1920/3, 1080},
                {{RenderSettings, 9}},
                SettingsGray,
                "assets/UI/Settings/SettingsRoundedCorner.png"
            );

            InitVideo();
            InitSound();
        }

        void Scroll()
        {
            //if( (posY + inputManager->WheelMovementY()) < 0 )
            {
                posY += inputManager->WheelMovementY();
            }
            //else
            {
            //    posY = 0;
            }

            ScrollVideo( posY );
            ScrollSound( posY );
        }

        void UpdateWindow()
        {
            box->Show();
            UpdateVideo();
            UpdateSound();
        }

    };

    extern Window *settingsWindow;

}