#pragma once

#include "../../inc/Global.h"

class SoundManager
{
    Mix_Music *music;
    int volume;

public:
    SoundManager( std::string path );
    ~SoundManager();

    void Play( int repeats = -1 );
    void Pause();
    void Resume();
    void Rewind();
    void SetVolume( int volume );
    void Halt();

    void Close();

    int Volume() { return volume; }
};