#pragma once

#include <SDL.h>
#include <SDL_mixer.h>

#include "../../inc/Metrics.h"

class Window
{

public:
    Window();
    ~Window();

    SDL_Window *window;
    SDL_Renderer *renderer;
};

extern Window *window;