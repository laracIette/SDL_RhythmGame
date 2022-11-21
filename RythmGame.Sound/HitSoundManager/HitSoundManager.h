#pragma once

#include "../HitSound/HitSound.h"

#include <vector>
#include <string>
#include <iostream>

namespace RythmGame::Sound
{

    class HitSoundManager
    {
        std::string hitSounds[8];

        std::vector<HitSound *> playingHitSounds;

    /*
        channels go from 0 to 255
    */
        unsigned char audioChannels;

        unsigned char lastAudioChannels;

    public:
        HitSoundManager();
        ~HitSoundManager();

        void Update();

        void Play( int pos );

        void Close();
    };

    extern HitSoundManager *hitSoundManager;
}
