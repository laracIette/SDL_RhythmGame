#pragma once

#include "../../Types/Options.h"

using namespace RythmGame::Game::Settings;

namespace RythmGame::Game::Settings::Video
{

    class SettingFPS : public Options
    {
        const int options[6] {
            30,
            60,
            120,
            240,
            480,
            960
        };

        int fps;

    public:
        SettingFPS( float _y ) :
            Options(
                "Video",
                "FPS",
                _y
            )
        {
            index = settingsFile->data["Video"]["FPS"]["index"];
            fps   = options[index];

            for( const int i : options )
            {
                vec.push_back( std::to_string( i ) );
            }
        }

        void InitFPS()
        {
            InitOptions();
        }

        void ScrollFPS( float _y )
        {
            ScrollOptions( _y );
        }

        void UpdateFPS()
        {
            UpdateOptions();
        }

        int GetFPS() { return fps; }
    };


}
