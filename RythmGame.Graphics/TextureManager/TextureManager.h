#ifndef RYTHMGAME_GRAPHICS_TEXTUREMANAGER_H
#define RYTHMGAME_GRAPHICS_TEXTUREMANAGER_H


#include "../../includes.h"


namespace RythmGame::Graphics
{

    class TextureManager
    {
    public:
        static SDL_Texture *LoadTexture( const char *path );
        static void DrawTexture( SDL_Texture *tex, SDL_Rect src, SDL_Rect dest );
    };

}

#endif // RYTHMGAME_GRAPHICS_TEXTUREMANAGER_H