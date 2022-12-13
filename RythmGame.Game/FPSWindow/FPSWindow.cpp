#include "FPSWindow.h"

namespace RythmGame::Game
{

    FPSWindow::FPSWindow()
    {
        backgroundBox = new BoxRoundedCorners(
            {1920-300, 1080-200, 300, 200},
            {{RenderStartScreen, 1}, {RenderMapSelection, 1}, {RenderGameplay, 1}, {RenderSettings, 1}},
            Red,
            "assets/UI/FPSWindowRoundedCorner.png"
        );

        fpsText = new Text(
            "0.00",
            {1920-150, 1080-100, 50, 60},
            {{RenderStartScreen, 0}, {RenderMapSelection, 0}, {RenderGameplay, 0}, {RenderSettings, 0}},
            Center
        );
    }

    FPSWindow::~FPSWindow()
    {
    }

    void FPSWindow::Update( float _value )
    {
        fpsValues.push_back( _value );
        if( fpsValues.size() > 100 )
        {
            fpsValues.erase( fpsValues.begin() );
        }

        float sumFps{ 0 };
        for( float value : fpsValues )
        {
            sumFps += value;
        }

        fpsText->SetText( shortenString( sumFps/(float)100, 4 ) );
        backgroundBox->Show();
        fpsText->Show();
    }

}