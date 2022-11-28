#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingMusicVolume : public Slider
    {
        int volume;

    public:
        SettingMusicVolume( int _posY ) :
            Slider(
                "Music",
                _posY,
                0,
                100
            )
        {
            volume = settingsFile->data["Sound"]["MusicVolume"]["value"];
        }

        void InitMusicVolume()
        {
            InitSlider();
        }

        void UpdateMusicVolume()
        {
            UpdateSlider();
        }

        void ScrollMusicVolume( int _posY )
        {
            Scroll( _posY );
        }

        void DrawMusicVolume()
        {
            DrawSlider();
        }

        int GetMusicVolume() { return volume; }
    };


}