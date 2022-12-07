#include "TextureManager.h"

namespace RythmGame::Graphics
{

    SDL_Texture *TextureManager::LoadTexture( const char *_path )
    {
        SDL_Surface *tempSurface{ IMG_Load( _path ) };

        SDL_Texture *tex{ SDL_CreateTextureFromSurface( window->renderer, tempSurface ) };

        SDL_FreeSurface( tempSurface );

        std::cout << _path << std::endl;

        if( !tex )
        {
            std::cout << "Error creating '" << _path << "'.\n" << SDL_GetError() << std::endl;
        }

        return tex;
    }

    void TextureManager::DrawTexture( SDL_Texture *_tex, Rect _dest )
    {
        SDL_RenderCopy( window->renderer, _tex, NULL, getPointer(getSDLRect(resize(_dest))) );
    }

}