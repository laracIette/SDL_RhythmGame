#include "TextureManager.h"

namespace RythmGame::Graphics
{

    SDL_Texture *TextureManager::LoadTexture( const char *path )
    {
        SDL_Surface *tempSurface{ IMG_Load( path ) };
        SDL_Texture *tex{ SDL_CreateTextureFromSurface( window->renderer, tempSurface ) };
        SDL_FreeSurface( tempSurface );

        if( !tex )
        {
            std::cout << "Error creating '" << path << "'.\n" << SDL_GetError() << std::endl;
        }

        return tex;
    }

    void TextureManager::DrawTexture( SDL_Texture *tex, SDL_Rect dest )
    {
        SDL_RenderCopy( window->renderer, tex, NULL, &dest );
    }

}