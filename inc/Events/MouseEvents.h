#pragma once

#include <SDL.h>

struct MouseEvents
{
    static const int BUTTONS{ 2 };

    unsigned char buttonCode[BUTTONS]{
        SDL_BUTTON_LEFT,
        SDL_BUTTON_RIGHT,

    };

    bool buttonPressed[BUTTONS]{ false };

};