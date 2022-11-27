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
        SettingFPS( int posX, int posY ) : Options( "FPS", posX, posY )
        {
            index = settingsFile->data["Video"]["FPS"]["index"];
            fps   = options[index];

            for( const int i : options )
            {
                vec.push_back( std::to_string( i ) );
            }

            Init( posY );
        }

        int GetFPS() { return fps; }

        void UpdateFPS( int newIndex )
        {
            index = newIndex;

            settingsFile->data["Video"]["FPS"]["value"] = options[index];
            settingsFile->writeData = true;
        }
    };


}
