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

struct HitTime
{
    const unsigned int Perfect{ 50 };
    const unsigned int Great{ 150 };
    const unsigned int Meh{ 300 };

    const unsigned int Max{ 450 };
};
struct HitAccuracy
{
    const char Perfect{ 1 };
    const char Great{ 3 };
    const char Meh{ 6 };
};
struct Hit
{
    HitTime Time;
    HitAccuracy Accuracy;
};

extern Hit hit;

extern int WIDTH;
extern int HEIGHT;

extern Window *window;


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

#define CoutEndl( arg ) std::cout << arg << std::endl;