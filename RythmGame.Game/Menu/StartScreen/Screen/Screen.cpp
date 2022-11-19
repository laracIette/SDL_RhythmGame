#include "Screen.h"

namespace RythmGame::Game::Menu::StartScreen
{

    Screen::Screen()
    {
        playButton        = new PlayButton();
        buttons[Exit]     = new ExitButton();
        buttons[Download] = new DownloadButton();
        buttons[Settings] = new SettingsButton();

        background = new Image(
            "assets/background.png",
            {0, 0, 1920, 1080},
            {Default::WIDTH/2, Default::HEIGHT/2, 1920, 1080}
        );
    }

    Screen::~Screen()
    {
    }

    void Screen::Update()
    {
        for( ButtonTemplate *button : buttons )
        {
            button->Hoover();
        }

        playButton->Update();
    }

    void Screen::Draw()
    {
        background->Draw();

        if( !playButton->IsClicked() )
        {
            for( ButtonTemplate *button : buttons )
            {
                button->DrawButton();
            }
        }
        playButton->DrawPlayButton();
    }

    bool Screen::StartGame()
    {
        return playButton->StartGame();
    }
    bool Screen::ExitButtonClicked()
    {
        return buttons[Exit]->Clicked();
    }
    bool Screen::DownloadButtonClicked()
    {
        return buttons[Download]->Clicked();
    }
    bool Screen::SettingsButtonClicked()
    {
        return buttons[Settings]->Clicked();
    }
}
