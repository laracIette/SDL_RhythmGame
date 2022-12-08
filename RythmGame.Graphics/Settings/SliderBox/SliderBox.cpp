#include "SliderBox.h"

namespace RythmGame::Graphics::Settings
{

    SliderBox::SliderBox( float _x, float _y )
    {
        sliderBar = new ImageCenter(
            "assets/UI/Settings/SliderBar.png",
            {_x, _y+20, 80, 40},
            RenderSettings,
            6
        );

        posY = _y;

    }

    SliderBox::~SliderBox()
    {
    }

    void SliderBox::Scroll( float _y )
    {
        sliderBar->SetY( posY+20 + _y );
    }

    void SliderBox::Update()
    {
        sliderBar->Show();
        sliderBar->Hoover();
    }

    bool SliderBox::IsHoover()
    {
        return sliderBar->IsHoover();
    }

}
