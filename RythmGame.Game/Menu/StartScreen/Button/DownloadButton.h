#pragma once

#include "Button.h"

namespace RythmGame::Game::Menu::StartScreen::Button
{

    class DownloadButton : public Button<ImageBottomRight>
    {

    public:
    /**
        DownloadButton inherits from Button
    */
        DownloadButton() :
            Button(
                "assets/Skins/BaseSkin/Menu/StartScreen/DownloadButton.png"
            )
        {}
    };

}