#pragma once

#include "../../inc/Global.h"
#include "../TextureManager/TextureManager.h"

class Image
{
    SDL_Texture *tex;
    SDL_Rect src;
    Rect dest;

public:
    Image( std::string path, SDL_Rect src, Rect dest );
    ~Image();

    void Draw();

    float X() { return dest.x; }
    float Y() { return dest.y; }
    float W() { return dest.w; }
    float H() { return dest.h; }

    void SetX( float x ) { dest.x = x; }
    void SetY( float y ) { dest.y = y; }
    void SetW( float w ) { dest.w = w; }
    void SetH( float h ) { dest.h = h; }
};
