#pragma once

#include <string>

#include "../SettingBox.h"

namespace RythmGame::Game::Settings
{

    class Slider : public SettingBox
    {
        int min, max;

    public:
        Slider( std::string _name, int _posY, int _min, int _max ) :
            SettingBox(
                _name,
                _posY
            )
        {
            min = _min;
            max = _max;
        }

        void InitSlider()
        {
            Init();
        }

        void UpdateSlider()
        {
            Update();
        }

        void DrawSlider()
        {
            DrawBackgroundBox();
            if( isSelected )
            {
            }
            else
            {
                DrawText();
            }
        }

    };

}
