#include "TextureManager.h"

namespace RythmGame::Graphics
{

    SDL_Texture *TextureManager::LoadTexture( std::string _path )
    {
        SDL_Surface *tempSurface{ IMG_Load( _path.c_str() ) };

        SDL_Texture *tex{ SDL_CreateTextureFromSurface( window->renderer, tempSurface ) };

        SDL_FreeSurface( tempSurface );

        if( !tex )
        {
            logFile->Write( "Error : creating '" + _path + "', " + SDL_GetError() );
        }

        return tex;
    }

    void TextureManager::DrawTexture( SDL_Texture *_tex, Rect _dest )
    {
        SDL_RenderCopy( window->renderer, _tex, NULL, getPointer(getSDLRect(resize(_dest))) );
    }

}