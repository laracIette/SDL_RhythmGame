#include "Check.h"

namespace RythmGame::Game::Settings::Option
{

    void Check::Update( int posY )
    {
        checkBoxOn->SetY( posY );
        checkBoxOff->SetY( posY );
        UpdateText( posY );

        checkBoxOn->Hoover();

        if( checkBoxOn->IsLeftClicked() )
        {
            value = !value;
        }
    }

    void Check::Draw()
    {
        (value) ? checkBoxOn->Draw() : checkBoxOff->Draw();
        DrawText();
    }

}