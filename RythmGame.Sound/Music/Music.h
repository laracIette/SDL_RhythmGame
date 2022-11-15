#ifndef RYTHMGAME_SOUND_MUSIC_H
#define RYTHMGAME_SOUND_MUSIC_H


#include "../../includes.h"


namespace RythmGame::Sound
{

    class Music
    {
        Mix_Music *music;
        int volume;

    public:
        Music( std::string path );
        ~Music();

    // infinite by default
        void Play( int repeats = -1 );
        void Pause();
        void Resume();
        void Rewind();
        void SetVolume( int volume );

        void Close();

        int Volume() { return volume; }
    };

}

#endif // RYTHMGAME_SOUND_MUSIC_H