#pragma once

#include "../../inc/Global.h"

class HitSound
{
    Mix_Chunk *hitSound;

    unsigned char channel;
    int volume;

public:
    HitSound( std::string path );
    ~HitSound();

// 1 by default
    void Play( int repeats = 1 );
    void Pause();
    void Resume();
    void SetVolume( int volume );

    void Close();
};