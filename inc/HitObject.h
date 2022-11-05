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

    bool isHit;
    bool isShown;
    bool isValueReturned;
    bool isHitValueReturned;

    float pos;

    char hitValue;


public:
    HitObject()
    {
        isHit            = false;
        isShown          = false;
        isValueReturned  = false;
        isHitValueReturned = false;

        offsetTime = 0;
    }
    ~HitObject() {}

    float X() { return objectImage->X(); }
    float Y() { return objectImage->Y(); }
    float W() { return objectImage->W(); }
    float H() { return objectImage->H(); }

    void SetX( float x ) { objectImage->SetX( x ); }
    void SetY( float y ) { objectImage->SetY( y ); }
    void SetW( float w ) { objectImage->SetW( w ); }
    void SetH( float h ) { objectImage->SetH( h ); }

    char GetHitValue()
    {
        if( isHitValueReturned )
        {
            isHitValueReturned = false;
            CoutEndl('v'<<(int)hitValue)
            return hitValue;
        }
        return -1;
    }

    virtual bool IsHit() { return isHit; }

    unsigned int time, offsetTime;

    bool isUp;

    unsigned char type, direction;

    unsigned int difference;


// initialises the HitObject
    virtual void Init() {}

// sets the pos of the HitObject
    virtual void Pos() { pos = (float)WIDTH/6 + ((float)time + (float)offsetTime - (float)currentTime)*velocity; }

// affects a value to hitValue
    void CheckHitTiming()
    {
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
        isHitValueReturned = true;
    }

// returns true if hitting the right note side
    bool CheckHitting()
    {
        if( (events.Clicked( events.mouse.Left ) && isUp)
         || (events.Clicked( events.mouse.Right ) && !isUp) )
            return 1;

        return 0;
    }


// does specific things by type if isHit
    virtual void DoThingsAfterHit()
    {
        if( W() > 2 )
        {
            SetW( W() - 0.1 );
            SetH( H() - 0.1 );
        }
        if( !isValueReturned )
        {
            isValueReturned = true;
            isHitValueReturned = true;
        }

    }

    void Update()
    {
        difference = abs( (int)currentTime-(int)offsetTime-(int)time );

        Pos();

        if( !isShown && (pos <= WIDTH + W()/2) )
        {
            isShown = true;
        }

        SetX( pos );

        if( !isHit && CheckHitting() && (difference < hit.Time.Max) )
        {
            CheckHitTiming();
        }

        if( isHit )
        {
            DoThingsAfterHit();
        }
    }

    void Draw()
    {
        if( isShown )
        {
            objectImage->Draw();
        }
    }

// returns true if the HitObject needs to be erased
    virtual bool Erase()
    {
        if( ((int)currentTime-(int)offsetTime-(int)time) > (int)hit.Time.Max )
            return 1;

        return 0;
    }
};

class Note : public HitObject
{
public:

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
    bool isHold;

    bool isEndHitValueReturned;

public:
    unsigned int endTime;

    void Init()
    {
        objectImage = new Image(
            "assets/Skins/BaseSkin/HitObjects/Holds/Hold0.png",
            {0, 0, 50, 50},
            {0, (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ), ((float)endTime - (float)time)*velocity + 50, 50}
        );

        isHold = true;
        isEndHitValueReturned = false;
    }

    void Pos()
    {
        pos = (float)WIDTH/6 + ((float)time + (float)offsetTime - (float)currentTime)*velocity + (W()/2-H()/2);
    }

    void DoThingsAfterHit()
    {
        if( (hitValue > 0) && !isEndHitValueReturned && !CheckHitting() )
        {
            isEndHitValueReturned = true;
            difference = abs( (int)currentTime-(int)offsetTime-(int)endTime );

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
            isHitValueReturned = true;
        }
    }

    bool IsHit()
    {
        return (isHit && isEndHitValueReturned) ;
    }

    bool Erase()
    {
        if( ((int)currentTime-(int)offsetTime-(int)endTime) > (int)hit.Time.Max )
            return 1;

        return 0;
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

    void Pos()
    {
        if( (currentTime >= time + offsetTime) && (currentTime < endTime + offsetTime) )
        {
            pos = (float)WIDTH/6;
        }
        else
        {
            pos = (float)WIDTH/6 + ((float)time + (float)offsetTime - (float)currentTime)*velocity;
        }
    }
};
class Ghost : public HitObject
{
public:

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