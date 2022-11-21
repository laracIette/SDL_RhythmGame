#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_gpu.h>

#include "../../RythmGame.Framework/Window/Window.h"

using namespace RythmGame::Framework;

namespace RythmGame::Graphics
{

    class TextureManager
    {
    public:
        static GPU_Image *LoadTexture( const char *path );
        static void DrawTexture( GPU_Image *tex, GPU_Rect *dest );
    };

}