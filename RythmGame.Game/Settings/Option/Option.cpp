#include "Option.h"

namespace RythmGame::Game::Settings
{

    Option::Option( const char *text )
    {
        SDL_Surface *tempSurface = TTF_RenderText_Blended( police, text, {255, 255, 255} );
        textTexture = SDL_CreateTextureFromSurface( window->renderer, tempSurface );
        if( !textTexture )
        {
            std::cout << "error creating text texture '" << text << "'" << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface( tempSurface );

    }

    Option::~Option()
    {
    }

    void Option::Update()
    {
        dest = {0, 0, 100, 300};
    }

    void Option::Draw()
    {
        SDL_RenderCopy( window->renderer, textTexture, NULL, &dest );
    }

}
