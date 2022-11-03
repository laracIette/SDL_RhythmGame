#pragma once

#include "../../inc/Global.h"

class SoundManager
{
    Mix_Music *music;

public:
    SoundManager();
    ~SoundManager();

    void Init( const char *path );

    void Play( int repeats );
};