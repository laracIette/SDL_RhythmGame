#pragma once

#include <SDL.h>

struct KeyboardEvents
{
    static const int KEYS{ 8 };

    SDL_KeyCode keyCode[KEYS]{
        SDLK_LEFT,
        SDLK_RIGHT,
        SDLK_UP,
        SDLK_DOWN,
        SDLK_a,
        SDLK_d,
        SDLK_w,
        SDLK_s
    };

    bool keyPressed[KEYS]{ false };
};