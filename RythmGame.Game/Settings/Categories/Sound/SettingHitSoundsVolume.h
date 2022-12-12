#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingHitSoundsVolume : public Slider
    {

    public:
        SettingHitSoundsVolume( float _y ) :
            Slider(
                "Sound",
                "HitSoundsVolume",
                _y,
                0.0f,
                100.0f
            )
        {
        }

        void InitHitSoundsVolume()
        {
            InitSlider();
        }

        void ScrollHitSoundsVolume( float _y )
        {
            ScrollSlider( _y );
        }

        void UpdateHitSoundsVolume()
        {
            UpdateSlider();
        }

        int GetHitSoundsVolume() { return (int)GetValue(); }
    };


}