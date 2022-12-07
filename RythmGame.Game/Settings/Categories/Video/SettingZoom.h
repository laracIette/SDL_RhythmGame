#pragma once

#include "../../Types/Slider.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Video
{

    class SettingZoom : public Slider<float>
    {

    public:
        SettingZoom( float _y ) :
            Slider(
                "Video",
                "Zoom",
                _y,
                0.5f,
                1.5f
            )
        {
        }

        void InitZoom()
        {
            InitSlider();
        }

        void ScrollZoom( float _y )
        {
            ScrollSlider( _y );
        }

        void UpdateZoom()
        {
            UpdateSlider();
        }

        float GetZoom() { return GetValue(); }

    };

}
