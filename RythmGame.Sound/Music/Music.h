#pragma once

#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include "../../inc/SDL2_mixer-2.6.2/include/SDL_mixer.h"
#include <string>

namespace RythmGame::Sound
{

    class Music
    {
        Mix_Music *music;
        int volume;

    public:
        Music( std::string path );
        ~Music();

    /**
        infinite by default
    */
        void Play( int repeats = -1 );
        void Pause();
        void Resume();
        void Rewind();
        void SetVolume( int volume );

        void Close();

        int Volume() { return volume; }
    };

}