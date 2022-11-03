#include "SoundManager.h"

SoundManager::SoundManager( std::string path )
{
    music = Mix_LoadMUS( const_cast<char *>( path.c_str() ) );

    if( music == nullptr )
    {
        SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "Error loading music : %s", Mix_GetError() );
    }
    volume = 128;
}
SoundManager::~SoundManager()
{
}

void SoundManager::Play( int repeats )
{
    Mix_PlayMusic( music, repeats );
}
void SoundManager::Pause()
{
    Mix_PauseMusic();
}
void SoundManager::Resume()
{
    Mix_ResumeMusic();
}
void SoundManager::Rewind()
{
    Mix_RewindMusic();
}
void SoundManager::SetVolume( int volume )
{
    this->volume = volume;
    Mix_VolumeMusic( volume );
}
void SoundManager::Halt()
{
    Mix_HaltMusic();
}

void SoundManager::Close()
{
    Mix_FreeMusic( music );
}