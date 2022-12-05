#pragma once

#include <string>

#include "../SettingBox.h"
#include "../../../RythmGame.Graphics/Settings/SliderBox/SliderBox.h"

using namespace RythmGame::Graphics::Settings;

namespace RythmGame::Game::Settings
{

    class Slider : public SettingBox
    {
        int min, max;

        int value;

        int midValue;

        float ratio;

        SliderBox *sliderBox;

    public:
        Slider( std::string _category, std::string _name, int _posY, int _min, int _max ) :
            SettingBox(
                _name,
                _posY
            )
        {
            min = _min;
            max = _max;

            midValue = (min+max)/2;

            ratio = 200 / (float)(midValue-min);

            value = settingsFile->data[_category][_name]["value"];
        }

        void InitSlider()
        {
            Init();

            sliderBox = new SliderBox( 1920/6 + (float)(value-midValue)*ratio, posY );
        }

        void ScrollSlider( int _posY )
        {
            Scroll( _posY );
            sliderBox->Scroll( _posY );
        }

        void UpdateSlider()
        {
            Update();
            sliderBox->Update();
        }

    };

}
