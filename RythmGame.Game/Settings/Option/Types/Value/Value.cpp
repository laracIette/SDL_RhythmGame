#include "Value.h"

namespace RythmGame::Game::Settings::Option
{

    std::pair<int, int> Value::Update( int posY )
    {
        UpdateText( posY );
        return {0, 0};
    }

    void Value::Draw()
    {
        DrawText();
    }

}