#include "Window.h"

namespace RythmGame::Game::Settings
{

    Window::Window()
    {
        box = new BoxRoundedCorners(
            {0, 0, 1920/3, 1080},
            {69, 69, 69},
            "assets/UI/Settings/SettingsRoundedCorner.png"
        );

        posY = 0;

        categoryVideo = new Video::Category( 0 );

    }

    Window::~Window()
    {
    }

    void Window::Update()
    {
        if( (posY + inputManager.WheelMovementY()) >= 0 )
        {
            posY += inputManager.WheelMovementY();
        }
    }

    void Window::Draw()
    {
        box->Draw();
        categoryVideo->Draw();
    }
}