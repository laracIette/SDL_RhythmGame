#include "HitSound.h"

HitSound::HitSound( std::string path )
{
    hitSound = Mix_LoadWAV( const_cast<char *>( path.c_str() ) );
    if( !hitSound )
    {
        std::cout << "Error creating '" << path << "'.\n" << SDL_GetError() << std::endl;
    }

    channel = audioChannels;
    if( ++audioChannels == 255 ) std::cout << "max number of channels affected" << std::endl;

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

    if( audioChannels != 0 ) audioChannels--;
    else                     std::cout << "already 0 channels affected" << std::endl;
}