#pragma once

#include <math.h>

extern int WIDTH;
extern int HEIGHT;

extern unsigned int FPS;


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