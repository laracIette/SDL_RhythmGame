#pragma once

#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include "../../inc/SDL2_image-2.6.2/SDL_image.h"
#include <iostream>

#include "../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Framework;

namespace RythmGame::Graphics
{

    class TextureManager
    {
    public:
        static SDL_Texture *LoadTexture( const char *path );
        static void DrawTexture( SDL_Texture *tex, SDL_Rect dest );
    };

}