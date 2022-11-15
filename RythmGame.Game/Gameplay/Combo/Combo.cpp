#include "Combo.h"

namespace RythmGame::Game::Gameplay
{

    unsigned int Combo::GetCombo()
    {
        return combo;
    }

    void Combo::AddCombo( unsigned int combo )
    {
        SetCombo( this->combo + combo );
    }

    void Combo::SetCombo( unsigned int combo )
    {
        this->combo = combo;
        SetText( std::to_string( combo ) );
    }

}

