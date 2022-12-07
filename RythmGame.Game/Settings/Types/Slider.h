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

        std::string category, name;

        float ratio;

        SliderBox *sliderBox;

        bool isSliderSelected;

    public:
        Slider( std::string _category, std::string _name, float _y, T _min, T _max ) :
            SettingBox(
                _name,
                _y
            )
        {
            category = _category;
            name     = _name;

            min = _min;
            max = _max;

            midValue = (min+max)/2;

            ratio = 200 / (float)(midValue-min);

            value = settingsFile->data[category][name]["value"];
            assertValueInRange( value, _min, _max );

        }

        void InitSlider()
        {
            Init();

            sliderBox = new SliderBox( 1920/6 + (value-midValue)*ratio, posY );

            isSliderSelected = false;
        }

        void ScrollSlider( float _y )
        {
            Scroll( _y );
            sliderBox->Scroll( _y );
        }

        void UpdateSlider()
        {
            Update();
            sliderBox->Update();

            if( !inputManager->LeftClicked() )
            {
                isSliderSelected = false;
                if( settingsFile->data[category][name]["value"] != value )
                {
                    settingsFile->data[category][name]["value"] = value;
                    settingsFile->isWriteData = true;
                }
            }
            else if( sliderBox->IsHoover()  )
            {
                isSliderSelected = true;
            }

            if( isSliderSelected )
            {
                T tempValue{ (T)((1920/6 - 200 - 40 + inputManager->MousePosX())/ratio) };
                if( (tempValue >= min) && (tempValue <= max) )
                {
                    sliderBox->SetX( inputManager->MousePosX() );
                    value = tempValue;
                }
            }
        }

        T GetValue() { return value; }

    };

}
