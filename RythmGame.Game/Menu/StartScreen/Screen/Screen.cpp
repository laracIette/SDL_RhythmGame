#include "Screen.h"

namespace RythmGame::Game::Menu::StartScreen
{

    Screen::Screen()
    {
        playButton = new PlayButton();
    }

    Screen::~Screen()
    {
    }

    void Screen::Update()
    {
        playButton->Hoover();
    }

    void Screen::Draw()
    {
        playButton->Draw();
    }
}
