#include "Window.h"
#include "../../inc/Global.h"

Window::Window()
{
    if( !SDL_Init( SDL_INIT_EVERYTHING ) )
    {
        window = SDL_CreateWindow( "Simu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0 );
        renderer = SDL_CreateRenderer( window, -1, 0 );

        SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
    }
}

Window::~Window()
{
}
