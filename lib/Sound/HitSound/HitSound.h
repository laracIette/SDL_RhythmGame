#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <iostream>

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
