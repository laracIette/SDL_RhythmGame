#pragma once

#include "../../Image/Image.h"

namespace RythmGame::Graphics::Settings
{

    class SliderBox
    {
        Image *sliderBar;

        int posY;

    public:
        SliderBox( float _posX, int _posY );
        ~SliderBox();

        void Scroll( int _posY );

        void Update();
    };


}
