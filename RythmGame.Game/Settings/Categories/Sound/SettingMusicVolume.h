#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingMusicVolume : public Slider
    {

    public:
        SettingMusicVolume( int _posY ) :
            Slider(
                "Sound",
                "MusicVolume",
                _posY,
                0,
                100
            )
        {
        }

        void InitMusicVolume()
        {
            InitSlider();
        }

        void ScrollMusicVolume( int _posY )
        {
            Scroll( _posY );
        }

        void UpdateMusicVolume()
        {
            UpdateSlider();
        }

        int GetMusicVolume() { return 0; }
    };


}