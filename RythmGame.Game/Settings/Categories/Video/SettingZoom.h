#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Video
{

    class SettingZoom : public Slider
    {

    public:
        SettingZoom( int _posY ) :
            Slider(
                "Video",
                "Zoom",
                _posY,
                50,
                150
            )
        {
        }

        void InitZoom()
        {
            InitSlider();
        }

        void ScrollZoom( int _posY )
        {
            ScrollSlider( _posY );
        }

        void UpdateZoom()
        {
            UpdateSlider();
        }

        int GetZoom() { return 0; }

    };

}
