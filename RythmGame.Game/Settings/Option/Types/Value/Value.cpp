#include "Value.h"

namespace RythmGame::Game::Settings::Option
{

    void Value::Update( int posY )
    {
        UpdateText( posY );
    }

    void Value::Draw()
    {
        DrawText();
    }

}