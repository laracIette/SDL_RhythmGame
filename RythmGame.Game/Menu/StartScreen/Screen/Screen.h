#pragma once

#include "../Button/PlayButton.h"
#include "../Button/ExitButton.h"
#include "../Button/DownloadButton.h"
#include "../Button/SettingsButton.h"

#include "../../../../RythmGame.Graphics/Image/Image.h"

using namespace RythmGame::Game::Menu::StartScreen::Button;
using namespace RythmGame::Graphics;


namespace RythmGame::Game::Menu::StartScreen
{

    class Screen
    {
        ButtonTemplate *buttons[4];
        Image *background;

    public:
        Screen();
        ~Screen();

        void Update();

        void Draw();

        bool PlayButtonClicked();
        bool ExitButtonClicked();
        bool DownloadButtonClicked();
        bool SettingsButtonClicked();
    };



}
