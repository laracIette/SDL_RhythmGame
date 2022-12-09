#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "../HitSound/HitSound.h"

#include "../../RythmGame.Framework/Log.h"

using namespace RythmGame::Framework;

namespace RythmGame::Sound
{

    class HitSoundManager
    {
        std::string hitSounds[8];

        std::vector<HitSound *> playingHitSounds;

    /**
        channels go from 0 to 255
    */
        unsigned char audioChannels;

        unsigned char lastAudioChannels;

    public:
        HitSoundManager();
        ~HitSoundManager();

        void Update();

        void Play( int _pos );

        void Close();
    };

    extern HitSoundManager *hitSoundManager;
}
