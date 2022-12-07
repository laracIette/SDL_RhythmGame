#pragma once

#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include "../../inc/SDL2_image-2.6.2/SDL_image.h"
#include <iostream>

#include "../../RythmGame.Framework/Window/Window.h"

#include "../../RythmGame.Game/Utils/GameSettings.h"

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Graphics
{

    class TextureManager
    {
    public:
        static SDL_Texture *LoadTexture( const char *_path );
        static void DrawTexture( SDL_Texture *_tex, Rect _dest );
    };

}