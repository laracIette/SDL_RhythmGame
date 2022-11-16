#pragma once

#include "../Button/PlayButton.h"

#include "../../../../RythmGame.Graphics/Image/Image.h"

using namespace RythmGame::Game::Menu::StartScreen::Button;
using namespace RythmGame::Graphics;


namespace RythmGame::Game::Menu::StartScreen
{

    class Screen
    {
        PlayButton *playButton;
        Image *background;

    public:
        Screen();
        ~Screen();

        void Update();

        void Draw();
    };



}
