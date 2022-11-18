#include "Combo.h"

namespace RythmGame::Game::Gameplay
{

    int Combo::GetCombo()
    {
        return combo;
    }

    void Combo::AddCombo( int combo )
    {
        SetCombo( this->combo + combo );
    }

    void Combo::SetCombo( int combo )
    {
        this->combo = combo;
        SetText( std::to_string( combo ) );
    }

}

