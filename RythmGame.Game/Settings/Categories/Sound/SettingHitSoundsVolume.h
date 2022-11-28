#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingHitSoundsVolume : public Slider
    {
        int volume;

    public:
        SettingHitSoundsVolume( int _posY ) :
            Slider(
                "HitSounds",
                _posY,
                0,
                100
            )
        {
            volume = settingsFile->data["Sound"]["HitSoundsVolume"]["value"];
        }

        void InitHitSoundsVolume()
        {
            InitSlider();
        }

        void UpdateHitSoundsVolume()
        {
            UpdateSlider();
        }

        void ScrollHitSoundsVolume( int _posY )
        {
            Scroll( _posY );
        }

        void DrawHitSoundsVolume()
        {
            DrawSlider();
        }

        int GetHitSoundsVolume() { return volume; }
    };


}