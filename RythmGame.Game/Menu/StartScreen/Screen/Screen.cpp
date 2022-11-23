#include "Screen.h"

namespace RythmGame::Game::Menu::StartScreen
{

    Screen::Screen()
    {
        playButton        = new PlayButton();
        buttons[Exit]     = new ExitButton();
        buttons[Download] = new DownloadButton();
        buttons[Settings] = new SettingsButton();

        background = new Background(
            "assets/Skins/BaseSkin/Menu/StartScreen/background.png"
        );
    }

    Screen::~Screen()
    {
    }

    void Screen::Update()
    {
        for( ButtonTemplate *button : buttons )
        {
            button->Update();
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
                button->Draw();
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
        return buttons[Exit]->IsLeftClicked();
    }
    bool Screen::DownloadButtonClicked()
    {
        return buttons[Download]->IsLeftClicked();
    }
    bool Screen::SettingsButtonClicked()
    {
        return buttons[Settings]->IsLeftClicked();
    }
}
