#include "Screen.h"

namespace RythmGame::Game::Menu::StartScreen
{

    Screen::Screen()
    {
        buttons[0] = new PlayButton();
        buttons[1] = new ExitButton();
        buttons[2] = new DownloadButton();
        buttons[3] = new SettingsButton();

        background = new Image( "assets/background.png", {0, 0, 1920, 1080}, {Default::WIDTH/2, Default::HEIGHT/2, 1920, 1080} );
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
    }

    void Screen::Draw()
    {
        background->Draw();

        for( ButtonTemplate *button : buttons )
        {
            button->DrawButton();
        }
    }

    bool Screen::PlayButtonClicked()
    {
        return buttons[0]->Clicked();
    }
    bool Screen::ExitButtonClicked()
    {
        return buttons[1]->Clicked();
    }
    bool Screen::DownloadButtonClicked()
    {
        return buttons[2]->Clicked();
    }
    bool Screen::SettingsButtonClicked()
    {
        return buttons[3]->Clicked();
    }
}
