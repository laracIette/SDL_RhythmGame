#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingGeneralVolume : public Slider<int>
    {

    public:
        SettingGeneralVolume( int _posY ) :
            Slider(
                "Sound",
                "GeneralVolume",
                _posY,
                0,
                100
            )
        {
        }

        void InitGeneralVolume()
        {
            InitSlider();
        }

        void ScrollGeneralVolume( int _posY )
        {
            Scroll( _posY );
        }

        void UpdateGeneralVolume()
        {
            UpdateSlider();
        }

        int GetGeneralVolume() { return 0; }
    };


}
