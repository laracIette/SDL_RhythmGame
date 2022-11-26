#include "Slider.h"

namespace RythmGame::Game::Settings::Option
{

    std::pair<int, int> Slider::Update( int posY )
    {
        UpdateText( posY );
        return {FONT_SIZE_OPTION, 0};
    }

    void Slider::Draw()
    {
        DrawText();
    }

}