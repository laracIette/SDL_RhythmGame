#include "HitSound.h"

HitSound::HitSound( std::string path )
{
    hitSound = Mix_LoadWAV( const_cast<char *>( path.c_str() ) );

    channel = audioChannels;
    if( ++audioChannels == 255 ) CoutEndl("max number of channels affected")

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
void HitSound::SetVolume( int volume )
{
    this->volume = volume;
    Mix_VolumeChunk( hitSound, 128 );
}

void HitSound::Close()
{
    Mix_FreeChunk( hitSound );

    (audioChannels != 0) ? audioChannels-- : CoutEndl("already 0 channels affected")
}