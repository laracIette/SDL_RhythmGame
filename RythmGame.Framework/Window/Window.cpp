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

    void Window::FillRectangle( Rect _dest, RGB _color )
    {
        SDL_SetRenderDrawColor( renderer, _color.r, _color.g, _color.b, 255 );
        SDL_RenderFillRect( renderer, getPointer(getSDLRect(resize(_dest))) );
    }

    void Window::DrawBox( Rect _dest, RGB _color )
    {
        SDL_Rect newRect{ getSDLRect(resize(_dest)) };

        SDL_SetRenderDrawColor( renderer, _color.r, _color.g, _color.b, 255 );
        SDL_RenderDrawLine( renderer, newRect.x,           newRect.y,           newRect.x+newRect.w, newRect.y );
        SDL_RenderDrawLine( renderer, newRect.x,           newRect.y,           newRect.x,           newRect.y+newRect.h );
        SDL_RenderDrawLine( renderer, newRect.x+newRect.w, newRect.y+newRect.h, newRect.x,           newRect.y+newRect.h );
        SDL_RenderDrawLine( renderer, newRect.x+newRect.w, newRect.y+newRect.h, newRect.x+newRect.w, newRect.y );
    }

}