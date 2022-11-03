#include "SoundManager.h"

SoundManager::SoundManager()
{
}
SoundManager::~SoundManager()
{
}

void SoundManager::Init( const char *path )
{
    music = Mix_LoadMUS( path );

    if( music == nullptr )
    {
        SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "Error loading music : %s", Mix_GetError() );
    }
}

void SoundManager::Play( int repeats )
{
    Mix_PlayMusic( music, repeats );
}