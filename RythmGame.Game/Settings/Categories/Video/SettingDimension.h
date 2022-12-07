#pragma once

#include "../../Types/Options.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Video
{

    class SettingDimension : public Options
    {
        const int options[27][2] {
            {640,  360},
            {768,  432},
            {896,  504},
            {1024, 576},
            {1152, 648},
            {1280, 720},
            {1408, 792},
            {1536, 864},
            {1600, 900},
            {1664, 936},
            {1792, 1008},
            {1920, 1080},
            {2048, 1152},
            {2176, 1224},
            {2304, 1296},
            {2432, 1368},
            {2560, 1440},
            {2688, 1512},
            {2816, 1584},
            {2944, 1656},
            {3072, 1728},
            {3200, 1800},
            {3328, 1872},
            {3456, 1944},
            {3584, 2016},
            {3712, 2088},
            {3840, 2160}
        };

        int width, height;

    public:
        SettingDimension( float _y ) :
            Options(
                "Dimension",
                _y
            )
        {
            index  = settingsFile->data["Video"]["Dimension"]["index"];
            width  = options[index][0];
            height = options[index][1];

            for( const int *arr : options )
            {
                vec.push_back( std::to_string( arr[0] ) + " x " + std::to_string( arr[1] ) );
            }
        }

        void InitDimension()
        {
            InitOptions();
        }

        void ScrollDimension( float _y )
        {
            ScrollOptions( _y );
        }

        void UpdateDimension()
        {
            UpdateOptions( "Video", "Dimension" );
        }

        int GetWidth()  { return width; }
        int GetHeight() { return height; }
    };


}
