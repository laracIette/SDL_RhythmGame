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
protected:
    Image *objectImage;

    float pos;

public:
    HitObject() {}
    ~HitObject() {}

    unsigned int time;
    bool isHit;
    bool isShown;

    unsigned char type, direction;

    virtual void Init() {}

    virtual void Move()
    {
        objectImage->SetX( pos );
    }

    void Update()
    {
        pos = (float)WIDTH/6 + ((float)time - (float)currentTime)*velocity;
        if( !isShown && (pos <= WIDTH) )
        {
            isShown = true;
        }
        Move();
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
        objectImage = new Image(
            "assets/Skins/BaseSkin/HitObjects/Notes/Note0.png",
            {0, 0, 50, 50},
            {0, (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ), 50, 50}
        );
    }

};
class Hold : public HitObject
{
public:
    unsigned int endTime;
    bool isUp;

    void Init()
    {
        objectImage = new Image(
            "assets/Skins/BaseSkin/HitObjects/Holds/Hold0.png",
            {0, 0, 50, 50},
            {0, (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ), ((float)endTime - (float)time)*velocity + 50, 50}
        );
    }

    void Move()
    {
        objectImage->SetX( pos + (objectImage->W()/2-objectImage->H()/2) );
    }
};
class Double : public HitObject
{
public:

    void Init()
    {
        objectImage = new Image(
            "assets/Skins/BaseSkin/HitObjects/Doubles/Double0.png",
            {0, 0, 50, 150},
            {0, (float)HEIGHT/2, 50, 150}
        );
    }
};
class Mash : public HitObject
{
public:
    unsigned int endTime;

    void Init()
    {
        objectImage = new Image(
            "assets/Skins/BaseSkin/HitObjects/Mashs/Mash0.png",
            {0, 0, 150, 150},
            {0, (float)HEIGHT/2, 150, 150}
        );
    }

    void Move()
    {
        if( (currentTime >= time) && (currentTime < endTime) )
        {
            pos = (float)WIDTH/6;
        }
        objectImage->SetX( pos );
    }
};
class Ghost : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        objectImage = new Image(
            "assets/Skins/BaseSkin/HitObjects/Ghosts/Ghost0.png",
            {0, 0, 50, 50},
            {0, (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ), 50, 50}
        );
    }
};
class Coin : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        objectImage = new Image(
            "assets/Skins/BaseSkin/HitObjects/Coins/Coin0.png",
            {0, 0, 25, 25},
            {0, (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ), 25, 25}
        );
    }
};
class Hammer : public HitObject
{
public:
    bool isUp;

    void Init()
    {
        objectImage = new Image(
            "assets/Skins/BaseSkin/HitObjects/Hammers/Hammer0.png",
            {0, 0, 50, 50},
            {0, (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ), 50, 50}
        );
    }
};
class Chainsaw : public HitObject
{
public:

    void Init()
    {
        objectImage = new Image(
            "assets/Skins/BaseSkin/HitObjects/Chainsaws/Chainsaw0.png",
            {0, 0, 50, 50},
            {0, (float)HEIGHT/2 + (float)HEIGHT/10, 50, 50}
        );
    }
};