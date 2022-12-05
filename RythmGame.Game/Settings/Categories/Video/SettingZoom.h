#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Video
{

    class SettingZoom : public Slider<float>
    {

    public:
        SettingZoom( int _posY ) :
            Slider(
                "Video",
                "Zoom",
                _posY,
                0.5f,
                1.5f
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

        float GetZoom() { return GetValue(); }

    };

}
