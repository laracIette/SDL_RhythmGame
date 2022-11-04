#pragma once

#include "../lib/Image/Image.h"


static float getHitObjectOffsetHeight( bool isUp )
{
    if( isUp ) return -(float)HEIGHT/10;
    return (float)HEIGHT/10;
}


class HitObject
{

protected:
    Image *objectImage;

    float pos;

    char hitValue;

public:
    HitObject() {}
    ~HitObject() {}

    float X() { return objectImage->X(); }
    float Y() { return objectImage->Y(); }
    float W() { return objectImage->W(); }
    float H() { return objectImage->H(); }

    void SetX( float x ) { objectImage->SetX( x ); }
    void SetY( float y ) { objectImage->SetY( y ); }
    void SetW( float w ) { objectImage->SetW( w ); }
    void SetH( float h ) { objectImage->SetH( h ); }

    unsigned int time, offsetTime;

    bool isHit;
    bool isShown;

    unsigned char type, direction;

    unsigned int difference;

    bool isValueReturned;

    virtual void Init() {}

    virtual void Move() { SetX( pos ); }

    virtual void Hit() {}

    char Update()
    {
        if( isHit )
        {
            if( W() > 2 )
            {
                SetW( W() - 0.1 );
                SetH( H() - 0.1 );
            }
            if( !isValueReturned )
            {
                isValueReturned = true;
                return hitValue;
            }
        }

        difference = abs( (int)currentTime-(int)offsetTime-(int)time );

        pos = (float)WIDTH/6 + ((float)time + (float)offsetTime - (float)currentTime)*velocity;
        if( !isShown && (pos <= WIDTH + W()/2) )
        {
            isShown = true;
        }

        Hit();
        Move();

        return -1;
    }

    void Draw()
    {
        if( isShown )
        {
            objectImage->Draw();
        }
    }

    bool Erase()
    {
        if( ((int)currentTime-(int)offsetTime-(int)time) > (int)hit.Time.Max )
            return 1;

        return 0;
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

    void Hit()
    {
        if( isHit )
            return;

        if( difference >= hit.Time.Max )
            return;

        if( !(events.Clicked( events.mouse.Left ) && isUp)
         && !(events.Clicked( events.mouse.Right ) && !isUp) )
            return;

        isHit = true;

        if( difference < hit.Time.Perfect )
        {
            hitValue = hit.Accuracy.Perfect;
        }
        else if( difference < hit.Time.Great )
        {
            hitValue = hit.Accuracy.Great;
        }
        else if( difference < hit.Time.Meh )
        {
            hitValue = hit.Accuracy.Meh;
        }
        else
        {
            hitValue = 0;
        }

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
        SetX( pos + (W()/2-H()/2) );
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
        if( (currentTime >= time + offsetTime) && (currentTime < endTime + offsetTime) )
        {
            pos = (float)WIDTH/6;
        }
        SetX( pos );
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