#pragma once

#include "../lib/Window/Window.h"
#include "Events/Events.h"
#include "Point.h"

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <fstream>

enum HitObjectTypes {
    NOTE = 1,
    HOLD,
    DOUBLE,
    MASH,
    GHOST,
    COIN,
    HAMMER,
    CHAINSAW
};

enum Directions {
    RIGHT = 1,
    LEFT,
    UP,
    DOWN
};


extern int WIDTH;
extern int HEIGHT;

extern Window *window;

extern vec2<int> mouse;


static unsigned int getTime()
{
    return SDL_GetTicks();
}

static void getTime( unsigned int &t )
{
    t = SDL_GetTicks();
}

extern unsigned int currentTime;
extern unsigned int deltaTime;

extern Events events;

struct Rect
{
    float x, y, w, h;
};


template<typename T>
static T deg( T r )
{
    return r * 180 / M_PI;
}

template<typename T>
static T rad( T d )
{
    return d * M_PI / 180;
}

extern float velocity;