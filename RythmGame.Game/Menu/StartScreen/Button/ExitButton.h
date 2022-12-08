#pragma once

#include "Button.h"

namespace RythmGame::Game::Menu::StartScreen::Button
{

    class ExitButton : public Button<ImageTopLeft>
    {

    public:
    /**
        ExitButton inherits from Button
    */
        ExitButton() :
            Button(
                "assets/Skins/BaseSkin/Menu/StartScreen/ExitButton.png"
            )
        {}
    };

}