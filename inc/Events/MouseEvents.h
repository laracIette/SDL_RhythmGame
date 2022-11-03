#pragma once

#include <SDL.h>
#include "../Point.h"

struct MouseEvents
{
    static const int BUTTONS{ 2 };

    unsigned char buttonCode[BUTTONS]{
        SDL_BUTTON_LEFT,
        SDL_BUTTON_RIGHT,

    };

    static const int Left{ 0 };
    static const int Right{ 1 };

    bool buttonClicked[BUTTONS]{ false };

    bool buttonLock[BUTTONS]{ false };

    vec2<int> pos;

};