#pragma once

#include "ButtonTemplate.h"

namespace RythmGame::Game::Menu::StartScreen::Button
{

    class DownloadButton : public ButtonTemplate
    {

    public:
    /*
        DownloadButton inherits from ButtonTemplate
    */
        DownloadButton() : ButtonTemplate(
            "assets/Skins/BaseSkin/Menu/StartScreen/DownloadButton.png",
            BottomRight
        )
        {}
    };

}