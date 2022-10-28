#pragma once

#include "../lib/Image/Image.h"


static void getHitObjectSkinImage( Image *img, float height, std::string path )
{
    img = new Image(
        "assets/Skins/HitObjects" + path + ".png",
        {0, 0, 50, 50},
        {1000, (float)HEIGHT/2 + height, 50, 50}
    );
}

static float getHitObjectOffsetHeight( bool isUp )
{
    if( isUp ) return -HEIGHT/10;
    else       return HEIGHT/10;
    return 0;
}


class HitObject
{
public:
    Image *objectImage;

    HitObject() {}
    ~HitObject() {}

    unsigned int time;
    bool isHit;

    unsigned char type;

    virtual void Init() {}

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
        float height{ getHitObjectOffsetHeight( isUp ) };
        getHitObjectSkinImage( objectImage, height, "Notes/Note0" );
    }
};
class Hold : public HitObject
{
public:
    unsigned int endTime;
    bool isUp;

    void Init()
    {
        float height{ getHitObjectOffsetHeight( isUp ) };
        getHitObjectSkinImage( objectImage, height, "Holds/Holds0" );
    }
};
class Double : public HitObject
{
public:

    void Init()
    {
        getHitObjectSkinImage( objectImage, 0, "Doubles/Double0" );
    }
};
class Mash : public HitObject
{
public:
    unsigned int endTime;

    void Init()
    {
        getHitObjectSkinImage( objectImage, 0, "Mashs/Mash0" );
    }
};
class Ghost : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        float height{ getHitObjectOffsetHeight( isUp ) };
        getHitObjectSkinImage( objectImage, height, "Ghosts/Ghost0" );
    }
};
class Coin : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        float height{ getHitObjectOffsetHeight( isUp ) };
        getHitObjectSkinImage( objectImage, height, "Coins/Coin0" );
    }
};
class Hammer : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        float height{ getHitObjectOffsetHeight( isUp ) };
        getHitObjectSkinImage( objectImage, height, "Hammers/Hammer0" );
    }
};
class Chainsaw : public HitObject
{
public:

    void Init()
    {
        getHitObjectSkinImage( objectImage, 0, "Chainsaws/Chainsaw0" );
    }
};