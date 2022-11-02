#pragma once

#include "../lib/Image/Image.h"


static float getHitObjectOffsetHeight( bool isUp )
{
    if( isUp ) return -(float)HEIGHT/10;
    else       return (float)HEIGHT/10;
    return 0;
}


class HitObject
{
    Image *objectImage;

public:
    HitObject()
    {

    }
    ~HitObject() {}

    unsigned int time;
    bool isHit;
    bool isShown;

    unsigned char type, direction;

    virtual void Init() {}


    void SetHitObjectImage( float height, std::string path )
    {
        objectImage = new Image(
            "assets/Skins/HitObjects/" + path + ".png",
            {0, 0, 50, 50},
            {1000, (float)HEIGHT/2 + height, 50, 50}
        );
    }

    void Move()
    {
        float pos{ (float)WIDTH/6 + ((float)time - (float)currentTime)*velocity };
        if( pos <= WIDTH )
        {
            isShown = true;
        }
        objectImage->SetX( pos );
    }

    void Draw()
    {
        if( isShown )
        {
            objectImage->Draw();
        }
    }
};

class Note : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        float height{ getHitObjectOffsetHeight( isUp ) };
        SetHitObjectImage( height, "Notes/Note0" );
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
        SetHitObjectImage( height, "Holds/Hold0" );
    }
};
class Double : public HitObject
{
public:

    void Init()
    {
        SetHitObjectImage( 0, "Doubles/Double0" );
    }
};
class Mash : public HitObject
{
public:
    unsigned int endTime;

    void Init()
    {
        SetHitObjectImage( 0, "Mashs/Mash0" );
    }
};
class Ghost : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        float height{ getHitObjectOffsetHeight( isUp ) };
        SetHitObjectImage( height, "Ghosts/Ghost0" );
    }
};
class Coin : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        float height{ getHitObjectOffsetHeight( isUp ) };
        SetHitObjectImage( height, "Coins/Coin0" );
    }
};
class Hammer : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        float height{ getHitObjectOffsetHeight( isUp ) };
        SetHitObjectImage( height, "Hammers/Hammer0" );
    }
};
class Chainsaw : public HitObject
{
public:

    void Init()
    {
        SetHitObjectImage( 0, "Chainsaws/Chainsaw0" );
    }
};