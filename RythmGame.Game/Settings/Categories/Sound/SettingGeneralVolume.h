#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingGeneralVolume : public Slider
    {

    public:
        SettingGeneralVolume( float _y ) :
            Slider(
                "Sound",
                "GeneralVolume",
                _y,
                0.0f,
                100.0f
            )
        {
        }

        void InitGeneralVolume()
        {
            InitSlider();
        }

        void ScrollGeneralVolume( float _y )
        {
            ScrollSlider( _y );
        }

        void UpdateGeneralVolume()
        {
            UpdateSlider();
        }

        int GetGeneralVolume() { return (int)GetValue(); }
    };


}
