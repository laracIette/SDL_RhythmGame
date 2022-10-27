#pragma once

#include "../lib/Image/Image.h"

class HitObject
{
public:
    Image *objectImage;

    HitObject() {}
    ~HitObject() {}

    unsigned int time;
    bool isHit;

    unsigned char type;

    void Move()
    {
        objectImage->SetX( objectImage->X() - velocity*deltaTime );
    }
};

class Note : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        int height;
        if( isUp ) height = -HEIGHT/10;
        else       height = HEIGHT/10;

        objectImage = new Image(
            "assets/Target/Target0.png",
            {0, 0, 50, 50},
            {1000, (float)HEIGHT/2 + height, 50, 50}
        );
    }
};
class Hold : public HitObject
{
public:
    unsigned int endTime;
    bool isUp;
};
class Double : public HitObject
{
public:
};
class Mash : public HitObject
{
public:
    unsigned int endTime;
};
class Ghost : public HitObject
{
public:
    bool isUp;
};
class Coin : public HitObject
{
public:
    bool isUp;
};
class Hammer : public HitObject
{
public:
    bool isUp;
};
class Chainsaw : public HitObject
{
public:
};