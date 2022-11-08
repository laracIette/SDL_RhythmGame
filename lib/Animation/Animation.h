#pragma once

#include "../Image/Image.h"

class Animation
{
    std::vector<Image *> images;
    unsigned int indice;
    unsigned int timeSinceLastImage;

public:
    Animation();
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
