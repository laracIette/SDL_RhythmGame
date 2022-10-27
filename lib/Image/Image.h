#pragma once

#include "../../inc/Global.h"
#include "../TextureManager/TextureManager.h"

class Image
{
    SDL_Texture *tex;
    SDL_Rect src;
    Rect dest;

public:
    Image( const char *path, SDL_Rect src, Rect dest );
    ~Image();

    void Draw();

    float X() { return dest.x; }
    float Y() { return dest.y; }

    void SetX( float x ) { dest.x = x; }
    void SetY( float y ) { dest.y = y; }
};
