#pragma once

#include <SDL.h>

class Window
{
public:
    Window();
    ~Window();

    SDL_Window *window;
    SDL_Renderer *renderer;
};

