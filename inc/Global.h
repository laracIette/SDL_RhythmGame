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
    LEFT = 1,
    RIGHT,
    UP,
    DOWN
};

struct HitTime
{
    enum Time {
        Perfect = 50,
        Great   = 150,
        Meh     = 300,
        Miss    = 450
    };
};
struct HitAccuracy
{
    enum Accuracy {
        Perfect = 0,
        Great   = 1,
        Meh     = 2,
        Miss    = 3
    };
};

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

extern unsigned int FPS;


extern unsigned int currentTime;
extern unsigned int deltaTime;
extern unsigned int offsetTime;


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

template<typename T>
static T highest( T a, T b )
{
    return (a > b) ? a : b;

}
template<typename T>
static T lowest( T a, T b )
{
    return (a < b) ? a : b;
}

extern bool isHorizontal;

// channels go from 0 to 255
extern unsigned char audioChannels;