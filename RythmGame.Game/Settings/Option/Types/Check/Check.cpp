#include "Check.h"

namespace RythmGame::Game::Settings::Option
{

    std::pair<int, int> Check::Update( int posY )
    {
        checkBoxOn->SetY( posY );
        checkBoxOff->SetY( posY );
        UpdateText( posY );

        checkBoxOn->Hoover();

        if( checkBoxOn->IsLeftClicked() )
        {
            value = !value;
        }

        return {FONT_SIZE_OPTION, 0};
    }

    void Check::Draw()
    {
        (value) ? checkBoxOn->Draw() : checkBoxOff->Draw();
        DrawText();
    }

}