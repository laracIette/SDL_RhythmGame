#pragma once

#include <iostream>
#include <string>

#include "../../inc/SDL-release-2.24.0/include/SDL.h"
#include "../../inc/SDL2_image-2.6.2/SDL_image.h"

#include "../../RythmGame.Framework/Window/Window.h"

#include "../../RythmGame.Game/Utils/GameSettings.h"

#include "../../RythmGame.Framework/Log.h"

using namespace RythmGame::Framework;
using namespace RythmGame::Game::Utils;

namespace RythmGame::Graphics
{

    class TextureManager
    {
    public:
        static SDL_Texture *LoadTexture( std::string _path );
        static void DrawTexture( SDL_Texture *_tex, Rect _dest );
    };

}