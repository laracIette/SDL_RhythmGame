#pragma once

#include <SDL.h>
#include <SDL_image.h>
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