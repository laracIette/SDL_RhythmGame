#include "Music.h"

Music::Music( std::string path )
{
    music = Mix_LoadMUS( const_cast<char *>( path.c_str() ) );

    if( music == nullptr )
    {
        SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "Error loading music : %s", Mix_GetError() );
    }
    volume = 128;
}
Music::~Music()
{
}

void Music::Play( int repeats )
{
    Mix_PlayMusic( music, repeats );
}
void Music::Pause()
{
    Mix_PauseMusic();
}
void Music::Resume()
{
    Mix_ResumeMusic();
}
void Music::Rewind()
{
    Mix_RewindMusic();
}
void Music::SetVolume( int volume )
{
    this->volume = volume;
    Mix_VolumeMusic( volume );
}

void Music::Close()
{
    Mix_FreeMusic( music );
}