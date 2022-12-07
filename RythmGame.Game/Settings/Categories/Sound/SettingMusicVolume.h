#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingMusicVolume : public Slider
    {

    public:
        SettingMusicVolume( float _y ) :
            Slider(
                "Sound",
                "MusicVolume",
                _y,
                0.0f,
                100.0f
            )
        {
        }

        void InitMusicVolume()
        {
            InitSlider();
        }

        void ScrollMusicVolume( float _y )
        {
            Scroll( _y );
        }

        void UpdateMusicVolume()
        {
            UpdateSlider();
        }

        int GetMusicVolume() { return (int)GetValue(); }
    };


}