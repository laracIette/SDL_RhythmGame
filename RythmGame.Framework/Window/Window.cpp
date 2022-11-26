#include "Window.h"

namespace RythmGame::Framework
{

    Window::Window()
    {
        int flags{ 0 };
        if( WIDTH == 1920 && HEIGHT == 1080 )
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }
        if( !SDL_Init( SDL_INIT_EVERYTHING ) )
        {
            window = SDL_CreateWindow( "RythmGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, flags );
            renderer = SDL_CreateRenderer( window, -1, 0 );
        }

        if( Mix_OpenAudio( 96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024 ) < 0 )
        {
            SDL_Log("Error initialisation SDL_mixer : %s", Mix_GetError());
        }
        Mix_AllocateChannels( 256 );

        if( TTF_Init() == -1 )
        {
            SDL_Log("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        }

    }

    Window::~Window()
    {
    }

    void Window::FillRectangle( SDL_Rect dest, RGB color )
    {
        SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, 255 );
        SDL_RenderFillRect( renderer, getPointer<SDL_Rect>(dest) );
    }

    void Window::DrawBox( SDL_Rect rect, RGB color )
    {
        SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, 255 );
        SDL_RenderDrawLine( renderer, rect.x, rect.y, rect.x+rect.w, rect.y );
        SDL_RenderDrawLine( renderer, rect.x, rect.y, rect.x, rect.y+rect.h );
        SDL_RenderDrawLine( renderer, rect.x+rect.w, rect.y+rect.h, rect.x, rect.y+rect.h );
        SDL_RenderDrawLine( renderer, rect.x+rect.w, rect.y+rect.h, rect.x+rect.w, rect.y );
    }

}