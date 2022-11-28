#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Sound
{

    class SettingGeneralVolume : public Slider
    {
        int volume;

    public:
        SettingGeneralVolume( int _posY ) :
            Slider(
                "General",
                _posY,
                0,
                100
            )
        {
            volume = settingsFile->data["Sound"]["GeneralVolume"]["value"];
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

        void DrawGeneralVolume()
        {
            DrawSlider();
        }

        int GetGeneralVolume() { return volume; }
    };


}
