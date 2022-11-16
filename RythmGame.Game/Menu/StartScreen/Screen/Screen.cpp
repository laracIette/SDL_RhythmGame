#include "Screen.h"

namespace RythmGame::Game::Menu::StartScreen
{

    Screen::Screen()
    {
        buttons[0] = new PlayButton();
        buttons[1] = new ExitButton();
        buttons[2] = new DownloadButton();
        buttons[3] = new SettingsButton();
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
        for( ButtonTemplate *button : buttons )
        {
            button->Draw();
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
