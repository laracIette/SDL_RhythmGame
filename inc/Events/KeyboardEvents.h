#pragma once

#include <SDL.h>

struct KeyboardEvents
{
    static const int KEYS{ 1 };

    SDL_KeyCode keyCode[KEYS]{
        SDLK_SPACE
    };

    static const int Space{ 0 };

    bool keyPressed[KEYS]{ false };

    bool keyLock[KEYS]{ false };
};