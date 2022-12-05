#pragma once

#include <string>

#include "../SettingBox.h"
#include "../../../RythmGame.Framework/asserts.h"
#include "../../../RythmGame.Graphics/Settings/SliderBox/SliderBox.h"

using namespace RythmGame::Graphics::Settings;
using namespace RythmGame::Framework;

namespace RythmGame::Game::Settings
{

    template<typename T>
    class Slider : public SettingBox
    {
        T min, max;

        T value;

        T midValue;

        T ratio;

        SliderBox *sliderBox;

        bool isSliderSelected;

    public:
        Slider( std::string _category, std::string _name, int _posY, T _min, T _max ) :
            SettingBox(
                _name,
                _posY
            )
        {
            min = _min;
            max = _max;

            midValue = (min+max)/2;

            ratio = 200 / (midValue-min);

            value = settingsFile->data[_category][_name]["value"];
            assertValueInRange( value, _min, _max );

        }

        void InitSlider()
        {
            Init();

            sliderBox = new SliderBox( 1920/6 + (value-midValue)*ratio, posY );

            isSliderSelected = false;
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

            if( !inputManager->LeftClicked() )
            {
                isSliderSelected = false;
            }
            else if( sliderBox->IsHoover()  )
            {
                isSliderSelected = true;
            }

            std::cout << isSliderSelected << std::endl;

            if( isSliderSelected )
            {
                sliderBox->SetX( (int)((float)inputManager->MousePosX()/WIDTH*1920) );//TODO
            }
        }

        T GetValue() { return value; }

    };

}
