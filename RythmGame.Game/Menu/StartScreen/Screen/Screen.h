#pragma once

#include "../Button/PlayButton.h"
#include "../Button/ExitButton.h"
#include "../Button/DownloadButton.h"
#include "../Button/SettingsButton.h"

#include "../../../Utils/GameSettings.h"

#include "../../../../RythmGame.Graphics/Background.h"

using namespace RythmGame::Game::Menu::StartScreen::Button;
using namespace RythmGame::Graphics;
using namespace RythmGame::Game::Utils;


namespace RythmGame::Game::Menu::StartScreen
{

    class Screen
    {
        ButtonTemplate *buttons[3];
        PlayButton *playButton;
        Background *background;

    public:
        Screen();
        ~Screen();

        void Update();

        bool StartGame();
        bool ExitButtonClicked();
        bool DownloadButtonClicked();
        bool SettingsButtonClicked();
    };



}
