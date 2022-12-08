#pragma once

#include "../../Image/Positions/ImageTopLeft.h"

using namespace RythmGame::Graphics;

namespace RythmGame::Graphics::Settings
{

    class CheckBox
    {
        ImageTopLeft *boxOn, *boxOff;

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