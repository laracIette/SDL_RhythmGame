#pragma once

#include <SDL.h>
#include "../Point.h"

struct MouseEvents
{
    static const int BUTTONS{ 3 };

    unsigned char buttonCode[BUTTONS]{
        SDL_BUTTON_LEFT,
        SDL_BUTTON_RIGHT,
        SDL_BUTTON_MIDDLE
    };

    enum Buttons {
        Left = 0,
        Right,
        Middle
    };

    bool buttonClicked[BUTTONS]{ false };

    bool buttonLock[BUTTONS]{ false };

    vec2<int> pos;

};