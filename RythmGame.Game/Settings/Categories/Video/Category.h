#pragma once

#include <vector>

#include "SettingDimension.h"
#include "SettingFPS.h"

namespace RythmGame::Game::Settings::Video
{

    class Category : public SettingDimension, public SettingFPS
    {

    public:
        Category( int posY ) : SettingDimension( posY ), SettingFPS( posY+FONT_SIZE_OPTION+6 )
        {
        }

        void InitVideo()
        {
            InitDimension();
            InitFPS();
        }

        void UpdateVideo()
        {
            UpdateDimension();
            UpdateFPS();
        }

        void DrawVideo()
        {
            DrawDimension();
            DrawFPS();
        }

    };


}