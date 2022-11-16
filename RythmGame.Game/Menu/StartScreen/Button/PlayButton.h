#pragma once

#include "ButtonTemplate.h"

namespace RythmGame::Game::Menu::StartScreen::Button
{

    class PlayButton : public ButtonTemplate
    {

    public:
        PlayButton() : ButtonTemplate(
            "assets/Skins/BaseSkin/Menu/StartScreen/PlayButton.png",
            BottomLeft
        )
        {}
    };

}