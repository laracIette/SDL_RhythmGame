#pragma once

#include "../../Image/Image.h"

namespace RythmGame::Graphics::Settings
{

    class SliderBox
    {
        Image *sliderBar;

        float posY;

    public:
        SliderBox( float _x, float _y );
        ~SliderBox();

        void Scroll( float _y );

        void Update();

        bool IsHoover();

        void SetX( float _x ) { sliderBar->SetX( _x ); }

        float X() { return sliderBar->X(); }
    };


}
