#include "TextureManager.h"

namespace RythmGame::Graphics
{

    GPU_Image *TextureManager::LoadTexture( const char *path )
    {
        SDL_Surface *tempSurface{ IMG_Load( path ) };
        GPU_Image *tex{ GPU_CopyImageFromSurface( tempSurface ) };
        SDL_FreeSurface( tempSurface );

        if( !tex )
        {
            std::cout << "Error creating '" << path << "'.\n" << SDL_GetError() << std::endl;
        }

        return tex;
    }

    void TextureManager::DrawTexture( GPU_Image *tex, GPU_Rect *dest )
    {
        GPU_BlitRect( tex, NULL, window->renderer, dest );
    }

}