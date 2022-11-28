#include "Combo.h"

namespace RythmGame::Game::Gameplay
{

    int Combo::GetCombo()
    {
        return combo;
    }

    void Combo::AddCombo( int _combo )
    {
        SetCombo( combo + _combo );
    }

    void Combo::SetCombo( int _combo )
    {
        combo = _combo;
        SetText( std::to_string( combo ) );
    }

}

