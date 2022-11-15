#ifndef RYTHMGAME_SOUND_HITSOUND_H
#define RYTHMGAME_SOUND_HITSOUND_H


#include "../../includes.h"


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

    // 1 by default
        void Play( int repeats = 1 );
        void Pause();
        void Resume();
        void SetVolume( int volume );
        void Halt();

        bool Playing();

        void Close();
    };

}

#endif // RYTHMGAME_SOUND_HITSOUND_H