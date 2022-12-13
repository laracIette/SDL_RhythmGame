#include "Window.h"

namespace RythmGame::Game::Settings
{

    void Window::InitWindow()
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

    void Window::Scroll()
    {
        if( (posY + inputManager->WheelMovementY()) < 0 )
        {
            posY += inputManager->WheelMovementY();
        }
        else
        {
            posY = 0;
        }

        ScrollVideo( posY );
        ScrollSound( posY );
    }

    void Window::UpdateWindow()
    {
        if( box->IsNotHooverLeftClicked() )
        {
            isHide = true;
            return;
        }

        isHide = false;

        box->Show();
        UpdateVideo();
        UpdateSound();
    }

}