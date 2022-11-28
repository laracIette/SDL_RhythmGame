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
        SettingFPS( int _posY ) :
            Options(
                "FPS",
                _posY
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

        void ScrollFPS( int _posY )
        {
            Scroll( _posY );
        }

        void UpdateFPS()
        {
            UpdateOptions();
        }

        void DrawFPS()
        {
            DrawOptions();
        }


        void ChangeFPS( int _index )
        {
            index = _index;

            settingsFile->data["Video"]["FPS"]["value"] = options[index];
            settingsFile->writeData = true;
        }

        int GetFPS() { return fps; }
    };


}