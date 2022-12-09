#pragma once

#include <string>
#include <iostream>

#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include "../../inc/SDL2_mixer-2.6.2/include/SDL_mixer.h"

#include "../../RythmGame.Framework/Log.h"

using namespace RythmGame::Framework;

namespace RythmGame::Sound
{

    class HitSound
    {
        Mix_Chunk *hitSound;

        unsigned char channel;
        int volume;

    public:
        HitSound( std::string path, unsigned char channel );
        ~HitSound();

    /**
        1 by default
    */
        void Play( int repeats = 1 );
        void Pause();
        void Resume();
        void SetVolume( int volume );
        void Halt();

        bool Playing();

        void Close();
    };

}