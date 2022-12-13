#include "Screen.h"

namespace RythmGame::Game::Menu::StartScreen
{

    Screen::Screen()
    {
        playButton     = new PlayButton();
        exitButton     = new ExitButton();
        downloadButton = new DownloadButton();
        settingsButton = new SettingsButton();

        background = new Background(
            "assets/Skins/BaseSkin/Menu/StartScreen/background.png",
            {{RenderStartScreen, 9}}
        );
    }

    Screen::~Screen()
    {
    }

    void Screen::Update()
    {
        playButton->Update();
        exitButton->Update();
        downloadButton->Update();
        settingsButton->Update();

        background->Show();

        if( !playButton->IsClicked() )
        {
            exitButton->Show();
            downloadButton->Show();
            settingsButton->Show();
        }
    }

    bool Screen::StartGame()
    {
        return playButton->StartGame();
    }
    bool Screen::ExitButtonClicked()
    {
        return exitButton->IsLeftClicked();
    }
    bool Screen::DownloadButtonClicked()
    {
        return downloadButton->IsLeftClicked();
    }
    bool Screen::SettingsButtonClicked()
    {
        return settingsButton->IsLeftClicked();
    }
}
