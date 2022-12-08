#pragma once

#include "Button.h"

namespace RythmGame::Game::Menu::StartScreen::Button
{

    class SettingsButton : public Button<ImageTopRight>
    {

    public:
    /**
        SettingsButton inherits from Button
    */
        SettingsButton() :
            Button(
                "assets/Skins/BaseSkin/Menu/StartScreen/SettingsButton.png"
            )
        {}
    };

}