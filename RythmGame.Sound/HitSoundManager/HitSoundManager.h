#ifndef RYTHMGAME_SOUND_HITSOUNDMANAGER_H
#define RYTHMGAME_SOUND_HITSOUNDMANAGER_H


#include "../../includes.h"


namespace RythmGame::Sound
{

    class HitSoundManager
    {
        std::string hitSounds[8];

        std::vector<HitSound *> playingHitSounds;

    // channels go from 0 to 255
        unsigned char audioChannels;

        unsigned char lastAudioChannels;

    public:
        HitSoundManager();
        ~HitSoundManager();

        void Update();

        void Play( int pos );

        void Close();
    };

}
extern RythmGame::Sound::HitSoundManager *hitSoundManager;

#endif // RYTHMGAME_SOUND_HITSOUNDMANAGER_H