#include "Window.h"

Window::Window()
{
    if( !SDL_Init( SDL_INIT_EVERYTHING ) )
    {
        window = SDL_CreateWindow( "SDL_RythmGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0 );
        renderer = SDL_CreateRenderer( window, -1, 0 );
    }

    if( Mix_OpenAudio( 96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024 ) < 0 )
    {
        SDL_Log("Error initialisation SDL_mixer : %s", Mix_GetError());
    }
    Mix_AllocateChannels( 256 );

}

Window::~Window()
{
}
