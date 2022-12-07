#pragma once

#include "../../Image/Image.h"

namespace RythmGame::Graphics::Settings
{

    class CheckBox
    {
        Image *boxOn, *boxOff;

        float posY;

        bool isOn;

    public:
        CheckBox( float _y, bool _isOn );
        ~CheckBox();

        void Scroll( float _y );

        void Update();

        bool GetIsOn() { return isOn; }
    };

}