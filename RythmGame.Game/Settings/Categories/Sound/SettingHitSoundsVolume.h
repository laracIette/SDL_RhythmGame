#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingHitSoundsVolume : public Slider
    {

    public:
        SettingHitSoundsVolume( int _posY ) :
            Slider(
                "Sound",
                "HitSoundsVolume",
                _posY,
                0,
                100
            )
        {
        }

        void InitHitSoundsVolume()
        {
            InitSlider();
        }

        void ScrollHitSoundsVolume( int _posY )
        {
            Scroll( _posY );
        }

        void UpdateHitSoundsVolume()
        {
            UpdateSlider();
        }

        int GetHitSoundsVolume() { return 0; }
    };


}