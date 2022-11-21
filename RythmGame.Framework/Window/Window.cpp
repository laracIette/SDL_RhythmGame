#include "Window.h"

namespace RythmGame::Framework
{

    Window::Window()
    {
        if( !SDL_Init( SDL_INIT_EVERYTHING ) )
        {
            renderer = GPU_Init( WIDTH, HEIGHT, GPU_DEFAULT_INIT_FLAGS );
        }

        if( Mix_OpenAudio( 96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024 ) < 0 )
        {
            SDL_Log("Error initialisation SDL_mixer : %s", Mix_GetError());
        }
        Mix_AllocateChannels( 256 );

        if(TTF_Init() == -1)
        {
            SDL_Log("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        }

    }

    Window::~Window()
    {
    }

}