#pragma once

#include <string>

#include "../../inc/SDL-release-2.24.0/include/SDL.h"


#include "Metrics.h"
#include "Point.h"

#define White                  (RGB){255, 255, 255}
#define Black                  (RGB){  0,   0,   0}
#define Red                    (RGB){255,   0, 255}
#define Green                  (RGB){  0, 255,   0}
#define Blue                   (RGB){  0,   0, 255}
#define SettingsGray           (RGB){ 69,  69,  69}
#define SettingsSettingBoxGray (RGB){ 50,  50,  50}
#define SettingsCategoryGray   (RGB){ 60,  60,  60}

namespace RythmGame::Game::Utils
{

    struct RGB
    {
        unsigned char r, g, b;

        inline RGB operator+( RGB _a )
        {
            return {(unsigned char)(r+_a.r), (unsigned char)(g+_a.g), (unsigned char)(b+_a.b)};
        }
        inline RGB operator-( RGB _a )
        {
            return {(unsigned char)(r-_a.r), (unsigned char)(g-_a.g), (unsigned char)(b-_a.b)};
        }
        inline RGB operator/( int _n )
        {
            return {(unsigned char)(r/_n), (unsigned char)(g/_n), (unsigned char)(b/_n)};
        }
    };

    extern float velocity;
    extern bool isHorizontal;

    template<typename T>
    static RGB getSongDifficultyColor( T _diff )
    {
        RGB ret = Black;

        if     ( _diff <= 1 ) ret = White;
        else if( _diff <= 2 ) ret = (White + Green)/2;
        else if( _diff <= 3 ) ret = Green;
        else if( _diff <= 4 ) ret = (Green + Blue)/2;
        else if( _diff <= 5 ) ret = Blue;
        else if( _diff <= 6 ) ret = (Blue + Red)/2;
        else if( _diff <= 7 ) ret = Red;
        else if( _diff <= 8 ) ret = (Red + Black)/2;

        return ret;
    }

/**
 * @brief number * WIDTH / 1920
 * @returns resized number
 */
    template<typename T>
    static inline T resize( T _n )
    {
        if( _n == 0 ) return _n;

        return (T)((float)_n * (float)WIDTH) / 1920;
    }

    static inline Rect resize( Rect _dest )
    {
        return {resize(_dest.x), resize(_dest.y), resize(_dest.w), resize(_dest.h)};
    }

    template<typename T>
    static inline T unsize( T _n )
    {
        if( _n == 0 ) return _n;

        return (T)((float)_n * 1920) / (float)WIDTH;
    }


/**
 * @returns new pointer to the passed argument.
 */
    template<typename T>
    static inline T *getPointer( T _arg )
    {
        return new T( _arg );
    }

    static inline SDL_Rect getSDLRect( Rect _dest )
    {
        return {(int)_dest.x, (int)_dest.y, (int)_dest.w, (int)_dest.h};
    }

    static inline Rect getRect( SDL_Rect _dest )
    {
        return {(float)_dest.x, (float)_dest.y, (float)_dest.w, (float)_dest.h};
    }

    template<typename T>
    static inline std::string shortenString( T _value, int _remove )
    {
        std::string value{ std::to_string( _value ) };

        std::string ret;
        for( int i{ 0 }; i < (value.size() - _remove); ++i )
        {
            ret += value[i];
        }

        return ret;
    }
}