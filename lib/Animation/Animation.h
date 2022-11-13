#pragma once

#include <filesystem>
#include <string>
#include <SDL.h>
#include <vector>

#include "../../inc/Point.h"
#include "../../inc/Time.h"

#include "../Image/Image.h"

class Animation
{
    std::vector<Image *> images;
    unsigned int indice;
    unsigned int timeSinceLastImage;

public:
    Animation( std::string path, SDL_Rect src, Rect dest );
    ~Animation();

    void Draw();

    float X();
    float Y();
    float W();
    float H();

    void SetX( float x );
    void SetY( float y );
    void SetW( float w );
    void SetH( float h );
};
