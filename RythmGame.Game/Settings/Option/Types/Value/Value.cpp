#include "Value.h"

namespace RythmGame::Game::Settings::Option
{

    std::pair<int, int> Value::Update( int posY )
    {
        UpdateText( posY );
        return {FONT_SIZE_OPTION, 0};
    }

    void Value::Draw()
    {
        DrawText();
    }

}