#pragma once

#include "../lib/Window/Window.h"
#include "Events/Events.h"
#include "Point.h"

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>

extern int WIDTH;
extern int HEIGHT;

extern Window *window;

extern vec2<int> mouse;

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