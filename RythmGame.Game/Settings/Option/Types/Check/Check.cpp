#include "Check.h"

namespace RythmGame::Game::Settings::Option
{

    void Check::Update( int posY )
    {
        checkBoxOn->SetY( posY );
        checkBoxOff->SetY( posY );
        UpdateText( posY );
    }

    void Check::Draw()
    {
        //(isOn) ? checkBoxOn->Draw() : checkBoxOff->Draw();
        DrawText();
    }

}