#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingGeneralVolume : public Slider<int>
    {

    public:
        SettingGeneralVolume( float _y ) :
            Slider(
                "Sound",
                "GeneralVolume",
                _y,
                0,
                100
            )
        {
        }

        void InitGeneralVolume()
        {
            InitSlider();
        }

        void ScrollGeneralVolume( float _y )
        {
            Scroll( _y );
        }

        void UpdateGeneralVolume()
        {
            UpdateSlider();
        }

        int GetGeneralVolume() { return 0; }
    };


}
