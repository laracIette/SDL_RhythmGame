#include "SliderBox.h"

namespace RythmGame::Graphics::Settings
{

    SliderBox::SliderBox( float _posX, int _posY )
    {
        sliderBar = new Image(
            "assets/UI/Settings/SliderBar.png",
            {_posX, (float)_posY+20, 80, 40},
            RenderSettings,
            6
        );

        posY = _posY;

    }

    SliderBox::~SliderBox()
    {
    }

    void SliderBox::Scroll( int _posY )
    {
        sliderBar->SetY( posY+20 + _posY );
    }

    void SliderBox::Update()
    {
        sliderBar->Show();
    }

}
