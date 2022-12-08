#include "CheckBox.h"

namespace RythmGame::Graphics::Settings
{

    CheckBox::CheckBox( float _y, bool _isOn )
    {
        posY = _y;

        boxOn = new ImageTopLeft(
            "assets/UI/Settings/CheckBoxOn.png",
            {1920/3-200, posY, 80, 40},
            RenderSettings,
            5
        );
        boxOff = new ImageTopLeft(
            "assets/UI/Settings/CheckBoxOff.png",
            {1920/3-200, posY, 80, 40},
            RenderSettings,
            5
        );

        isOn = _isOn;
    }

    CheckBox::~CheckBox()
    {
    }

    void CheckBox::Scroll( float _y )
    {
        boxOn->SetY( posY + _y );
        boxOff->SetY( posY + _y );
    }

    void CheckBox::Update()
    {
        boxOn->Hoover();
        if( boxOn->IsHooverLeftClicked() )
        {
            isOn = !isOn;
        }

        (isOn) ? boxOn->Show() : boxOff->Show();
    }

}
