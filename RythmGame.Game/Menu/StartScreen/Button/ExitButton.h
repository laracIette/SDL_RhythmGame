#pragma once

#include "ButtonTemplate.h"

namespace RythmGame::Game::Menu::StartScreen::Button
{

    class ExitButton : public ButtonTemplate
    {

    public:
        ExitButton() : ButtonTemplate(
            "assets/Skins/BaseSkin/Menu/StartScreen/ExitButton.png",
            TopLeft
        )
        {}
    };

}