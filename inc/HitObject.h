#pragma once

#include "../lib/Animation/Animation.h"


static float getHitObjectOffsetHeight( bool isUp )
{
    if( isUp ) return -(float)HEIGHT/10;
    return (float)HEIGHT/10;
}


class HitObject : public Animation
{

protected:
    bool isHit;
    bool isShown;
    bool isValueReturned;
    bool isReturnHitValue;

    float pos;

    char hitValue;

public:
    unsigned char type, direction;

    unsigned int time;

    unsigned int difference;

    bool isUp;

// HitObject inherits from Image
    HitObject( std::string path, SDL_Rect src, Rect dest ) : Animation( path, src, dest )
    {
        isHit            = false;
        isShown          = false;
        isValueReturned  = false;
        isReturnHitValue = false;
    }

// returns the hitValue if isReturnHitValue is true
// else returns -1
    char GetHitValue()
    {
        if( isReturnHitValue )
        {
            isReturnHitValue = false;
            CoutEndl('v'<<(int)hitValue)
            return hitValue;
        }
        return -1;
    }

    virtual bool IsHit() { return isHit; }


// initialises the HitObject
    virtual void Init() {}

// sets the pos of the HitObject
    virtual void Pos() { pos = (float)WIDTH/6 + ((float)time + (float)offsetTime - (float)currentTime)*velocity; }

// affects a value to hitValue
    void CheckHitTiming()
    {
        isHit = true;

        if( difference < HitTime::Perfect )
        {
            hitValue = HitAccuracy::Perfect;
        }
        else if( difference < HitTime::Great )
        {
            hitValue = HitAccuracy::Great;
        }
        else if( difference < HitTime::Meh )
        {
            hitValue = HitAccuracy::Meh;
        }
        else
        {
            hitValue = HitAccuracy::Miss;
        }
        isReturnHitValue = true;
    }

// returns true if hitting the right note side
    virtual bool CheckHitting()
    {
        if( (events.OnlyRight1Pressed() && isUp)
         || (events.OnlyRight2Pressed() && !isUp) )
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
            isReturnHitValue = true;
        }

    }


    void Update()
    {
        difference = abs( (int)currentTime - (int)offsetTime - (int)time );

        Pos();

        if( !isShown && (pos <= WIDTH + W()/2) )
        {
            isShown = true;
        }

        SetX( pos );

        if( !isHit && (difference < HitTime::Miss) && CheckHitting() )
        {
            CheckHitTiming();
        }

        if( isHit )
        {
            DoThingsAfterHit();
        }
    }

// draws the HitObject if isShown is true
    void DrawHitObject()
    {
        if( isShown )
        {
            Draw();
        }
    }

// returns true if the HitObject needs to be erased
    virtual bool Erase()
    {
        if( ((int)currentTime - (int)offsetTime - (int)time) > (int)HitTime::Miss )
            return 1;

        return 0;
    }
};



class Note : public HitObject
{

public:
    Note()
     : HitObject(
        "assets/Skins/BaseSkin/HitObjects/Notes",
        {0, 0, 2048, 2048},
        {0, 0, 50, 50}
    )
    {}

    void Init()
    {
        SetY( (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ) );
    }

};



class Hold : public HitObject
{
    bool isHold;

    bool isEndHitValueReturned;

public:
    unsigned int endTime;

    Hold()
     : HitObject(
        "assets/Skins/BaseSkin/HitObjects/Holds",
        {0, 0, 50, 50},
        {0, 0, 0, 50}
    )
    {}

    void Init()
    {
        SetY( (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ) );
        SetW( ((float)endTime - (float)time)*velocity + 50 );

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
            difference = abs( (int)currentTime - (int)offsetTime - (int)endTime );

            CheckHitTiming();
        }
    }

    bool IsHit()
    {
        return (isHit && isEndHitValueReturned) ;
    }

    bool Erase()
    {
        if( ((int)currentTime - (int)offsetTime - (int)endTime) > (int)HitTime::Miss )
            return 1;

        return 0;
    }

};



class Double : public HitObject
{
    bool isUpPressed, isDownPressed;
    unsigned int upPressedTime, downPressedTime;

public:
    Double()
     : HitObject(
        "assets/Skins/BaseSkin/HitObjects/Doubles",
        {0, 0, 50, 150},
        {0, (float)HEIGHT/2, 50, 150}
    )
    {}

    void Init()
    {
        isUpPressed = false;
        isDownPressed = false;
    }

    bool CheckHitting()
    {
    // register moment for each click
        if( !isUpPressed && events.OnlyRight1Pressed() )
        {
            isUpPressed = true;
            upPressedTime = currentTime;
        }
        if( !isDownPressed && events.OnlyRight2Pressed() )
        {
            isDownPressed = true;
            downPressedTime = currentTime;
        }
    // hitValue = highest difference from time
        if( isUpPressed && isDownPressed )
        {
            difference = highest(
                abs( (int)upPressedTime - (int)offsetTime - (int)time ),
                abs( (int)downPressedTime - (int)offsetTime - (int)time )
            );
            return 1;
        }

        return 0;
    }
};



class Mash : public HitObject
{
    unsigned int hits;
    unsigned int lastHitTime;

    bool isHitBlocked;


public:
    unsigned int endTime;

    Mash()
     : HitObject(
        "assets/Skins/BaseSkin/HitObjects/Mashs",
        {0, 0, 150, 150},
        {0, (float)HEIGHT/2, 150, 150}
    )
    {}

    void Init()
    {
        hits = 0;
        isHitBlocked = false;
    }

    void Pos()
    {
        if( currentTime < (time + offsetTime) )
        {
            pos = (float)WIDTH/6 + ((float)time + (float)offsetTime - (float)currentTime)*velocity;
        }
        else if( currentTime >= (endTime + offsetTime) )
        {
            pos = (float)WIDTH/6 + ((float)endTime + (float)offsetTime - (float)currentTime)*velocity;
        }
        else
        {
            pos = (float)WIDTH/6;
        }
    }

    bool CheckHitting()
    {
        if( !events.RightPressed() )
            return 0;

        if( difference < HitTime::Meh )
        {
            isHit = true;

            hitValue = HitAccuracy::Perfect;

            lastHitTime = currentTime;
        }

        return 0;
    }

    void DoThingsAfterHit()
    {
        if( isHitBlocked )
            return;

        if( ((int)currentTime - (int)offsetTime - (int)endTime) > HitTime::Meh )
        {
            isReturnHitValue = true;
            isHitBlocked = true;
            return;
        }

        if( (currentTime - lastHitTime) > 333 )
        {
            isHitBlocked = true;
            hitValue = HitAccuracy::Miss;
            isReturnHitValue = true;
        }

        if( !events.RightPressed() )
            return;

        if( events.Right1Pressed() && !events.KeyLock( events.rightKey1 ) )
        {
            hits++;
            events.SetKeyLock( events.rightKey1, true );
        }
        if( events.Right2Pressed() && !events.KeyLock( events.rightKey2 ) )
        {
            hits++;
            events.SetKeyLock( events.rightKey2, true );
        }

        lastHitTime = currentTime;

    }

    bool Erase()
    {
        if( ((int)currentTime-(int)offsetTime-(int)endTime) > (int)HitTime::Miss )
            return 1;

        return 0;
    }
};



class Ghost : public HitObject
{
public:
    Ghost()
     : HitObject(
        "assets/Skins/BaseSkin/HitObjects/Ghosts",
        {0, 0, 50, 50},
        {0, 0, 50, 50}
    )
    {}

    void Init()
    {
        SetY( (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ) );
    }

};



class Coin : public HitObject
{
public:
    Coin()
     : HitObject(
        "assets/Skins/BaseSkin/HitObjects/Coins",
        {0, 0, 25, 25},
        {0, 0, 25, 25}
    )
    {}

    void Init()
    {
        SetY( (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ) );
    }

    bool CheckHitting()
    {
        if( ( (events.OnlyRight1Pressed() && isUp) || ((events.OnlyRight2Pressed() && !isUp)) )
         && difference < HitTime::Meh )
        {
            hitValue = HitAccuracy::Perfect;
            isReturnHitValue = true;
            isHit = true;
        }
        return 0;
    }

};



class Hammer : public HitObject
{
public:
    Hammer()
     : HitObject(
        "assets/Skins/BaseSkin/HitObjects/Hammers",
        {0, 0, 50, 50},
        {0, 0, 50, 50}
    )
    {}

    void Init()
    {
        SetY( (float)HEIGHT/2 + getHitObjectOffsetHeight( isUp ) );
    }

};



class Chainsaw : public HitObject
{
    bool isHitLock;

public:
    Chainsaw()
     : HitObject(
        "assets/Skins/BaseSkin/HitObjects/Chainsaws",
        {0, 0, 2048, 2048},
        {0, (float)HEIGHT/2 + (float)HEIGHT/10, 50, 50}
    )
    {}

    void Init()
    {
        isHitLock = false;
    }

    bool CheckHitting()
    {
        if( (events.Right1Pressed() && isUp)
         || (events.Right2Pressed() && !isUp)
         || (!events.RightPressed() && !isUp)
         && difference < HitTime::Great )
        {
            isHit = true;
        }
        return 0;
    }

    bool IsHit()
    {
        if( !isHitLock && isHit )
        {
            isHitLock = true;
            return 1;
        }

        return 0;
    }

    void DoThingsAfterHit() {}
};