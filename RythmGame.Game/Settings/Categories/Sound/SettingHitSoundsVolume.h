#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingHitSoundsVolume : public Slider<int>
    {

    public:
        SettingHitSoundsVolume( float _y ) :
            Slider(
                "Sound",
                "HitSoundsVolume",
                _y,
                0,
                100
            )
        {
        }

        void InitHitSoundsVolume()
        {
            InitSlider();
        }

        void ScrollHitSoundsVolume( float _y )
        {
            Scroll( _y );
        }

        void UpdateHitSoundsVolume()
        {
            UpdateSlider();
        }

        int GetHitSoundsVolume() { return 0; }
    };


}