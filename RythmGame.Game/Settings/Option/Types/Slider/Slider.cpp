#include "Slider.h"

namespace RythmGame::Game::Settings::Option
{

    void Slider::Update( int posY )
    {
        UpdateText( posY );
    }

    void Slider::Draw()
    {
        DrawText();
    }

}