#pragma once

#include <SDL.h>

struct KeyboardEvents
{
    static const int KEYS{ 1 };

    SDL_KeyCode keyCode[KEYS]{
        SDLK_SPACE
    };

    bool keyPressed[KEYS]{ false };
};