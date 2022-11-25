#include "Slider.h"

namespace RythmGame::Game::Settings::Option
{

    std::pair<int, int> Slider::Update( int posY )
    {
        UpdateText( posY );
        return {0, 0};
    }

    void Slider::Draw()
    {
        DrawText();
    }

}