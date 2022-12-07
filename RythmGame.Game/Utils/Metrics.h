#pragma once

#include <math.h>

namespace RythmGame::Game::Utils
{

    extern int WIDTH;
    extern int HEIGHT;

    extern int FPS;


    template<typename T>
    static inline T deg( T _r )
    {
        return _r * 180 / M_PI;
    }

    template<typename T>
    static inline T rad( T _d )
    {
        return _d * M_PI / 180;
    }

    template<typename T>
    static inline T highest( T _a, T _b )
    {
        return (_a > _b) ? _a : _b;

    }
    template<typename T>
    static inline T lowest( T _a, T _b )
    {
        return (_a < _b) ? _a : _b;
    }

    static inline float round( float _v, float _precision )
    {
        return (float)((int)(_v * pow(10, _precision) + .5)) / pow(10, _precision);
    }

}