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
            isOn = !isOn;
        }
    }

    void Check::Draw()
    {
        (isOn) ? checkBoxOn->Draw() : checkBoxOff->Draw();
        DrawText();
    }

}