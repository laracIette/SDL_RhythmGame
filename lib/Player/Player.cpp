#include "Player.h"

void Player::Input()
{
    up   = false;
    down = true;

    upHit     = false;
    downHit   = false;

    if( events.Pressed( events.rightKey1 ) && events.Pressed( events.rightKey2 ) )
    {
        up   = false;
        down = false;

        upHit   = true;
        downHit = true;
    }

    else if( events.Pressed( events.rightKey1 ) )
    {
        up = true;

        upHit = true;
    }

    else if( events.Pressed( events.rightKey2 ) )
    {
        downHit = true;
    }


    if( up )
    {
        SetY( HEIGHT/2 - HEIGHT/10 );
    }
    else if( down )
    {
        SetY( HEIGHT/2 + HEIGHT/10 );
    }
    else
    {
        SetY( HEIGHT/2 );
    }


    //if( upHit )   CoutEndl("up")
    //if( downHit ) CoutEndl("up")
}