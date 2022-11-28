#include "HitSound.h"

namespace RythmGame::Sound
{

    HitSound::HitSound( std::string path, unsigned char _channel )
    {
        hitSound = Mix_LoadWAV( const_cast<char *>( path.c_str() ) );
        if( !hitSound )
        {
            std::cout << "Error creating '" << path << "'.\n" << SDL_GetError() << std::endl;
        }

        channel = _channel;

        volume = 128;
    }

    HitSound::~HitSound()
    {
    }

    void HitSound::Play( int repeats )
    {
        Mix_PlayChannel( channel, hitSound, repeats-1 );
    }
    void HitSound::Pause()
    {
        Mix_HaltChannel( channel );
    }
    void HitSound::Resume()
    {
        Mix_Resume( channel );
    }
    void HitSound::SetVolume( int _volume )
    {
        volume = _volume;
        Mix_VolumeChunk( hitSound, 128 );
    }
    void HitSound::Halt()
    {
        Mix_HaltChannel( channel );
    }

    bool HitSound::Playing()
    {
        return Mix_Playing( channel );
    }

    void HitSound::Close()
    {
        Halt();
        Mix_FreeChunk( hitSound );
    }

}