#pragma once

#include <vector>

#include "../../inc/SDL-release-2.24.0/include/SDL.h"

#include "../TextureManager/TextureManager.h"

namespace RythmGame::Graphics
{

    class RenderQueue
    {
        std::vector<std::pair<SDL_Texture *, SDL_Rect &>> queue[5];

    public:
        RenderQueue();
        ~RenderQueue();

        void AddQueue( SDL_Texture *_tex, SDL_Rect &_dest, int _index );

        void DrawRenderQueue();
    };

    extern RenderQueue *renderQueue;

}