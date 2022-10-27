#pragma once

#include "../Image/Image.h"

class Target : public Image
{
    float velocity;

public:
    Target( float height ) : Image(
        "assets/Target/Target0.png",
        {0, 0, 50, 50},
        {1000, (float)HEIGHT/2 + height, 50, 50}
    )
    {
        velocity = 0.1;
    }

    void Move();
};

class TargetUp : public Target
{
public:
    TargetUp() : Target( -HEIGHT/10 )
    {}
};

class TargetDown : public Target
{
public:
    TargetDown() : Target( HEIGHT/10 )
    {}
};